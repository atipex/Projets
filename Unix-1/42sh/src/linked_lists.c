#include <stdlib.h>
#include "42sh.h"

void	remove_elem(t_cmd *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
