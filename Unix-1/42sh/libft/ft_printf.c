#include <stdlib.h>
#include "ft_printf.h"
#include "lib.h"

char	*gimme_flags_tab(void)
{
  char	*flags_tab;

  flags_tab = malloc(sizeof(*flags_tab) * 5);
  if (flags_tab == NULL)
    return (NULL);
  flags_tab[0] = 'c';
  flags_tab[1] = 's';
  flags_tab[2] = 'd';
  flags_tab[3] = 'C';
  flags_tab[4] = 0;
  return (flags_tab);
}

ptr_funct	*gimme_ptr_funct(void)
{
  ptr_funct	*functions;

  functions = malloc(sizeof(*functions) * 5);
  if (functions == NULL)
    return (NULL);
  functions[0] = aff_char;
  functions[1] = aff_str;
  functions[2] = aff_nbr;
  functions[3] = aff_color;
  functions[4] = 0;
  return (functions);
}

void		check_flag(char *str, va_list ap,
			   ptr_funct *functions, char *flags_tab)
{
  int		i;

  i = 0;
  if (*str == '%')
    ft_putchar('%');
  else
    {
      while (flags_tab[i] && *str != flags_tab[i])
	i++;
      if (flags_tab[i])
	functions[i](ap);
    }
}

void		ft_printf(char *str, ...)
{
  int		i;
  va_list	ap;
  ptr_funct	*functions;
  char		*flags_tab;

  i = 0;
  va_start(ap, str);
  flags_tab = gimme_flags_tab();
  functions = gimme_ptr_funct();
  if (flags_tab == NULL || functions == NULL)
    return ;
  while (str[i])
    if (str[i++] == '%')
      check_flag(str + i++, ap, functions, flags_tab);
    else
      ft_putchar(str[i - 1]);
  va_end(ap);
  free(flags_tab);
  free(functions);
}
