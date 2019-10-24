#include "linked_list.h"

void	list_pushback(t_list *list_dest, t_node *node)
{
	t_node	*last_node;
	
	node->next = 0x0;
	node->prev = 0x0;
	if (!list_dest->first)
	{
		list_dest->first = node;
		list_dest->last = node;
	}
	else
	{
		last_node = list_dest->last;
		last_node->next = node;
		node->prev = list_dest->last;
		list_dest->last = node;
	}
	list_dest->len++;
}