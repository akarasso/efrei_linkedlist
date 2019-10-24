#include "linked_list.h"

void	list_foreach(t_list *l, void (*exec_func)(int, void*, void *), void *data)
{
	t_node	*ptr;
	int		index;

	ptr = l->first;
	index = 0;
	while (ptr)
	{
		exec_func(index, ptr, data);
		index++;
		ptr = ptr->next;
	}
}