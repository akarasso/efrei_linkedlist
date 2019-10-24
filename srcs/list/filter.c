#include "linked_list.h"

void	list_filter(t_list *l, int (*filter_func)(t_node*, void*), void *data)
{
	t_node *ptr;
	t_node *ptr_next;

	ptr = l->first;
	while (ptr)
	{
		ptr_next = ptr->next;
		if (filter_func(ptr, data) != 0)
		{
			l->len--;
			if (ptr->prev)
				ptr->prev->next = ptr->next;
			else
				l->first = ptr->next;
			if (ptr->next)
				ptr->next->prev = ptr->prev;
			else
				l->last = ptr->prev;
			free(ptr);
		}
		ptr = ptr_next;
	}
}