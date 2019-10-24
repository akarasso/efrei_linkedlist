#include "linked_list.h"

t_list	*list_map(t_list *origin, void *func_copy_node(t_node *), void func_delete_node(t_node *))
{
	t_list	*new;
	t_node	*new_node;
	t_node	*ptr;

	new = list_create(0x0);
	if (!new)
		return 0x0;
	ptr = origin->first;
	while (ptr)
	{
		new_node = func_copy_node(ptr);
		if (!new_node)
		{
			list_free(&new, func_delete_node);
			return 0x0;
		}
		list_pushback(new, new_node);
		ptr = ptr->next;
	}
	return new;
}