
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
int		ft_printf(const char *str, ...)__attribute__((format(printf, 1, 2)));
int		ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		ft_putstr(char const *s);
int		ft_putnbr(int n);
int		ft_putuint(unsigned int n);
int		ft_convert_hex(unsigned int nb, int caps);
int		ft_convert_oct(unsigned int nb);
int		count_ret(const char *str, int size, int retret);
char	*ft_itoa(int n);
char	*ft_itoa_unsint(unsigned int n);
size_t	ft_strlen(const char *s);
#endif
