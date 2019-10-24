#include "linked_list.h"

void	*list_get_index(t_list *list, int index)
{
	int		i;
	t_node	*node;

	i = 0;
	node = list->first;
	while (node && i < index)
	{
		node = node->next;
		i++;
	}
	return node;
}