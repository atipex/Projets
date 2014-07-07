
#include <stdarg.h>
#include <stdlib.h>
#include "ft.h"
int     ft_push_args(t_arg **list, t_arg *element)
{
  t_arg *tmp;

  tmp = *list;
  element->next = NULL;
  if ((*list) == NULL)
    {
      (*list) = element;
      return (1);
    }
  while ((*list)->next != NULL)
    {
      (*list) = (*list)->next;
    }
  (*list)->next = element;
  (*list) = tmp;
  return (0);
}
