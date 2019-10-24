#include "linked_list.h"

int		check_match_string(t_char_node *cnode, char *str)
{
	while (cnode && str)
	{
		if (cnode->data != *str)
			break;
		str++;
		cnode = cnode->next;
	}
	if (!*str)
		return 0;
	return 1;
}

int		do_replace(t_char_node *cnode, char *match, char *replace)
{
	t_char_node *new_cnode;
	t_char_node *next_cnode;
	t_char_node *prev_cnode;

	while (*replace && *match)
	{
		cnode->data = *replace;
		match++;
		replace++;
		cnode = cnode->next;
	}
	if (*match)
	{
		prev_cnode = cnode->prev;
		while (*match && cnode)
		{
			next_cnode = cnode->next;
			free(cnode);
			match++;
			cnode = next_cnode;
		}
		if (!cnode)
			prev_cnode->next = 0x0;
		else
		{
			prev_cnode->next = cnode;
			cnode->prev = prev_cnode;
		}
	}
	if (*replace)
	{
		prev_cnode = cnode->prev;
		while (*replace)
		{
			new_cnode = node_create_char(*replace);
			if (!new_cnode)
			{
				prev_cnode->next = cnode;
				cnode->prev = prev_cnode;
				return FATAL_ERROR;
			}
			new_cnode->prev = prev_cnode;
			prev_cnode->next = new_cnode;
			prev_cnode = new_cnode;
			replace++;
		}
		prev_cnode->next = cnode;
		cnode->prev = prev_cnode;
	}
	return SUCCESS;
}

void	node_njump(t_char_node **node, int n)
{
	while (n > 0 && node && *node)
	{
		if (*node)
			*node = (*node)->next;
		n--;
	}
}

int		match_replace(t_list *string, char *match, char *replace)
{
	t_char_node *cnode;
	int			len_match;
	int			len_replace;

	len_match = strlen(match);
	len_replace = strlen(replace);
	cnode = (t_char_node*)string->first;
	while (cnode)
	{
		if (check_match_string(cnode, match) == 0)
		{
			if (do_replace(cnode, match, replace) != SUCCESS)
				return FATAL_ERROR;
			node_njump(&cnode, len_replace);
			string->len = string->len - len_match + len_replace;
		}
		else
			cnode = cnode->next;
	}
	return SUCCESS;
}

int		menu_replace()
{
	int		index_string;
	t_node	*main_node;
	int		ret;
	char	*match;
	char	*replace;

	ret = get_user_input_index(&index_string, "Please enter index from string:");
	if (ret != SUCCESS)
		return ret;
	main_node = list_get_index(lists, index_string);
	if (!main_node)
	{
		printf("Failed to get string from index %d\n", index_string);
		return ERROR;
	}
	print_string(index_string, main_node, 0x0);
	printf("Enter substring to search:\n");
	if (get_user_input_string(&match) == ERROR)
		return FATAL_ERROR;
	printf("Enter list new substring:\n");
	if (get_user_input_string(&replace) == ERROR)
	{
		free(match);
		return FATAL_ERROR;
	}
	if (match_replace(main_node->data, match, replace) == SUCCESS)
		return SUCCESS;
	return FATAL_ERROR;
}