
#include <stdarg.h>
#include <stdlib.h>
#include "ft.h"
int     ft_push_flag(t_flag **list, int value)
{
  t_flag *element;
  t_flag *tmp;

  tmp = *list;
  element = malloc(sizeof(*element));
  if (element == NULL)
    return (1);
  element->data = value;
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
