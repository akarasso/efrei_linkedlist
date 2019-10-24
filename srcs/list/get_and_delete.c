#include "linked_list.h"

void	*list_get_and_delete_node(t_list *list, void *addr, void *func_to_free(void*))
{
	t_node	*node;

	node = list_get_and_remove_node(list, addr);
	if (node)
	{
		if (func_to_free)
			func_to_free(node);
		else
			free(node);
	}
	return node;
}