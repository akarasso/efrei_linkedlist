#include "linked_list.h"

int		list_insert_list(t_list *list_dest, t_list *list_src, int index)
{
	t_node *node;

	node = 0x0;
	if (!list_dest || !list_src || !list_src->len)
		return SUCCESS;
	node = list_get_index(list_dest, index);
	if (!node)
	{
		if (!list_dest->first)
			list_dest->first = list_src->first;
		if (list_dest->last)
			list_dest->last->next = list_src->first;
		list_src->first->prev = list_dest->last;
		list_dest->last = list_src->last;
		list_dest->len += list_src->len;
		return SUCCESS;
	}
	if (node->prev)
	{
		node->prev->next = list_src->first;
		list_src->first->prev = node->prev;
	}
	else
		list_dest->first = list_src->first;
	if (!node->next)
		list_dest->last = list_src->last;
	node->prev = list_src->last;
	list_src->last->next = node;
	list_dest->len += list_src->len;
	return SUCCESS;
}