#include "linked_list.h"

void	*list_get_and_remove_node(t_list *list, void *addr)
{
	t_node	*node;

	if ((node = list_get(list, addr)))
	{
		if (list->first == node)
		{
			if (node->next)
				node->next->prev = 0x0;
			list->first = node->next;
			list->len--;
		}
		else if (list->last == node)
		{
			if (node->prev)
				node->prev->next = 0x0;
			list->last = node->prev;
			list->len--;
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
	}
	return node;
}