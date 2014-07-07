#include "lib.h"
#include "ft_printf.h"

void	homemade_usleep()
{
  int	i;

  i = 0;
  while (i < 2899999)
    i++;
}

int	main()
{
  int	percent;
  int	equals;

  percent = 0;
  equals = 0;
  while (percent <= 100)
    {
      equals = percent / 10;
      ft_printf("\r%C[ %d%% ] [", "GREEN", percent);
      while (equals--)
	ft_printf("%C==", "GREEN");
      equals = percent / 10;
      while (10 - equals++)
	ft_putstr("  ", 1);
      ft_printf("%C]", "GREEN");
      percent = percent + 1;
      homemade_usleep();
    }
  ft_putchar('\n');
  return (0);
}
