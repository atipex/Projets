#include <stdlib.h>
#include "ft_printf.h"
#include "lib.h"

t_color	g_color_tab[10] =
  {
    {"RED", RED},
    {"CYAN", CYAN},
    {"GREEN", GREEN},
    {"BLACK", BLACK},
    {"YELLOW", YELLOW},
    {"BLUE", BLUE},
    {"PURPLE", PURPLE},
    {"GREY", GREY},
    {"WHITE", WHITE},
    {NULL, NULL}
  };

void	aff_char(va_list ap)
{
  ft_putchar((char)va_arg(ap, int));
}

void	aff_str(va_list ap)
{
  ft_putstr(va_arg(ap, char *), 1);
}

void	aff_nbr(va_list ap)
{
  ft_put_nbr(va_arg(ap, int));
}

void	aff_color(va_list ap)
{
  int	i;
  char	*color;

  i = 0;
  color = va_arg(ap, char *);
  while (g_color_tab[i].color &&
	 !ft_strncmp(g_color_tab[i].color, color, ft_strlen(color)))
    i++;
  if (g_color_tab[i].color)
    ft_putstr(g_color_tab[i].code, 1);
}
