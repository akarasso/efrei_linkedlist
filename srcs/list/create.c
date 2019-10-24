#include "linked_list.h"

t_list		*list_create()
{
	t_list		*new;

	new = malloc(sizeof(*new));
	if (!new)
		return 0x0;
	new->first = 0x0;
	new->last = 0x0;
	new->len = 0;
	return new;
}

t_node		*node_create(void *data)
{
	t_node		*new;

	new = malloc(sizeof(*new));
	if (!new)
		return 0x0;
	new->next = 0x0;
	new->prev = 0x0;
	new->data = data;
	return new;
}
