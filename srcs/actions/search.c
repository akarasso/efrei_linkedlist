#include "linked_list.h"

void	print_index_match_string(int index, void *node, void *data)
{
	if (check_match_string(node, data) == 0)
		printf("'%s' found at position %d\n", (char*)data, index);
}

int		menu_search()
{
	int		index_string;
	t_node	*main_node;
	char	*match;

	if (get_user_input_index(&index_string, "Please enter index from string ") != SUCCESS)
		return FATAL_ERROR;
	main_node = list_get_index(lists, index_string);
	if (!main_node)
	{
		printf("Failed to get string from index %d\n", index_string);
		return ERROR;
	}
	print_string(index_string, main_node, 0x0);
	printf("Enter list of char to search:\n");
	if (get_user_input_string(&match) != SUCCESS)
		return FATAL_ERROR;
	list_foreach(main_node->data, print_index_match_string, match);
	return SUCCESS;
}