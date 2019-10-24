#include "linked_list.h"

void	*node_create_char(char data)
{
	t_char_node		*new;

	new = malloc(sizeof(*new));
	if (!new)
		return 0x0;
	new->next = 0x0;
	new->prev = 0x0;
	new->data = data;
	return new;
}

int		list_char_create(t_list **new_char_list)
{
	t_char_node	*node;
	char		*str;
	int			i;

	*new_char_list = list_create();
	if (!*new_char_list)
		return FATAL_ERROR;
	if (get_user_input_string(&str) == ERROR) {
		free(*new_char_list);
		return ERROR;
	}
	i = 0;
	while (str[i])
	{
		node = node_create_char(str[i]);
		if (!node)
		{
			free(str);
			list_free(new_char_list, 0x0);
			return FATAL_ERROR;
		}
		list_pushback(*new_char_list, (t_node*)node);
		i++;
	}
	free(str);
	return SUCCESS;
}

int		menu_add_entrie()
{
	t_list *new_char_list;
	t_node *new_node;

	write(1, "Enter new char list:", 20);
	if (list_char_create(&new_char_list) != SUCCESS) {
		printf("Fatal error exiting program...\n");
		return FATAL_ERROR;
	}
	new_node = node_create(new_char_list);
	if (!new_node)
	{
		list_free(&new_char_list, 0x0);
		printf("Fatal error exiting program...\n");
		return FATAL_ERROR;
	}
	list_pushback(lists, new_node);
	return SUCCESS;
}