#include "linked_list.h"

int		filter_by_string(t_node *node, void *data)
{
	t_char_node	*cnode;
	char		*str;

	if (data)
	{
		cnode = (t_char_node*)node;
		str = data;
		while (*str && *str != cnode->data)
			str++;
		return (*str == cnode->data) ? 1 : 0;
	}
	return (0);
}

int		menu_delete_char()
{
	int		index_string;
	char	*char_to_delete;
	t_node	*main_node;

	if (get_user_input_index(&index_string, "Please enter first index from string ") != SUCCESS)
		return FATAL_ERROR;
	main_node = list_get_index(lists, index_string);
	if (!main_node)
	{
		printf("Failed to get string from index %d\n", index_string);
		return ERROR;
	}
	print_string(index_string, main_node, 0x0);
	printf("Enter list of char to delete:\n");
	if (get_user_input_string(&char_to_delete) != SUCCESS)
		return FATAL_ERROR;
	list_filter(((t_list*)main_node->data), filter_by_string, char_to_delete);
	free(char_to_delete);
	return SUCCESS;
}