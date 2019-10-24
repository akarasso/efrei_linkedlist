#include "linked_list.h"

void	print_string(int index, void *node, void *data)
{
	t_list		*string;
	t_char_node	*cnode;

	(void)index;
	(void)data;
	string = ((t_node*)node)->data;
	cnode = (t_char_node*)string->first;
	printf("Index:%d Len:%d {", index, string->len);
	while (cnode)
	{
		printf("%c", cnode->data);
		cnode = cnode->next;
	}
	printf("}\n");
}

void	print_header()
{
	write(1, "--------------------------------------------------------------------------------\n", 81);
	write(1, "| Lists                                                                        |\n", 81);
	write(1, "--------------------------------------------------------------------------------\n", 81);
}

int		print_entries()
{
	if (lists->len == 0)
		write(1, "No entries\n", 11);
	else
	{
		print_header();
		list_foreach(lists, print_string, 0x0);
		write(1, "--------------------------------------------------------------------------------\n", 81);
	}
	return SUCCESS;
}