#include <stdlib.h>
#include "ft.h"
int	put_flags(int cnt, char *str, t_arg *args)
{
  args->flags = NULL;
  while (is_flags(cnt, str, "-+ #0") != -1)
    {
      ft_push_flag(&args->flags, is_flags(cnt, str, "-+ #0"));
      cnt += 1;
    }
  return (cnt);
}
