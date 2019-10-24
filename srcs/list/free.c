#include "linked_list.h"

void	list_free(t_list **l, void func_free_node(t_node *))
{
	t_node *ptr;
	t_node *ptr_next;

	if (l && *l)
	{
		ptr = (*l)->first;
		while (ptr)
		{
			ptr_next = ptr->next;
			if (func_free_node)
				func_free_node(ptr);
			else
				free(ptr);
			ptr = ptr_next;
		}
		free(*l);
		*l = 0x0;
	}
}