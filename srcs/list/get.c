#include "linked_list.h"

void	*list_get(t_list *list, void *addr)
{
	t_node	*node;

	node = list->first;
	while (node && node != addr)
		node = node->next;
	return node;
}