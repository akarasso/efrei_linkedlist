#include "linked_list.h"

void	*copy_char_node(t_node *node_origin)
{
	return node_create_char(((t_char_node*)node_origin)->data);
}

int		menu_copy()
{
	int			index;
	t_node		*main_node;
	t_node		*new_main_node;
	t_list		*copy;

	if (get_user_input_index(&index, "Please enter index from string to copy ") == ERROR)
		return ERROR;
	main_node = list_get_index(lists, index);
	if (!main_node)
	{
		printf("Failed to get string\n");
		return ERROR;
	}
	copy = list_map(main_node->data, copy_char_node, 0x0);
	if (!copy)
	{
		printf("Failed to copy string\n");
		return ERROR;
	}
	new_main_node = node_create(copy);
	if (!new_main_node)
	{
		printf("Failed to add new string\n");
		return ERROR;
	}
	list_pushback(lists, new_main_node);
	return SUCCESS;
}