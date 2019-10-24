#include "linked_list.h"

int		menu_insert()
{
	int			index_string;
	int			index_pos;
	t_node		*main_node;
	t_list		*new_char_list;

	index_string = 0;
	index_pos = 0;
	if (get_user_input_index(&index_string, "Please enter index from string ") != SUCCESS)
		return FATAL_ERROR;
	main_node = list_get_index(lists, index_string);
	if (!main_node)
	{
		printf("Failed to get string from index %d\n", index_string);
		return ERROR;
	}
	if (get_user_input_position(&index_pos, main_node->data, "Please enter index from string ") != SUCCESS)
		return FATAL_ERROR;
	printf("Enter subtring to insert:\n");
	if (list_char_create(&new_char_list) != SUCCESS)
	{
		printf("Failed to allocate new string\n");
		return FATAL_ERROR;
	}
	if (list_insert_list(main_node->data, new_char_list, index_pos) ==  SUCCESS)
	{
		free(new_char_list);
		return SUCCESS;
	}
	printf("Failed to insert substring\n");
	return ERROR;
}