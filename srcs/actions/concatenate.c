#include "linked_list.h"

int		menu_concat_get_input(int *index1, int *index2)
{
	if (get_user_input_index(index1, "Please enter first index from string ") != SUCCESS)
		return FATAL_ERROR;
	if (get_user_input_index(index2, "Please enter second index from string ") != SUCCESS)
		return FATAL_ERROR;
	return SUCCESS;
}

void	menu_concat_list(t_list *l1, t_list *l2)
{
	if (l1->len == 0	)
	{
		l1->first = l2->first;
		l1->last = l2->last;
		l1->len = l2->len;
	}
	else
	{
		l1->last->next = l2->first;
		l2->first->prev = l1->last;
		l1->last = l2->last;
		l1->len += l2->len;
	}
	free(l2);
}

int		menu_concat()
{
	t_node *node1;
	t_node *node2;
	int		index1;
	int		index2;
	
	if (menu_concat_get_input(&index1, &index2) != SUCCESS)
		return FATAL_ERROR;	
	if (index1 == index2) {
		printf("Same index, nothing to do\n");
		return SUCCESS;
	}
	node1 = list_get_index(lists, index1);
	node2 = list_get_and_remove_index(lists, index2);
	if (node1 && node2)
	{
		menu_concat_list(node1->data, node2->data);
		return SUCCESS;
	}
	return ERROR;
}