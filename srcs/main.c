#include "linked_list.h"

int	init_folder()
{
	struct stat	st;

	if (stat("./data", &st) == -1) {
		mkdir("./data", 0700);
	}
	return SUCCESS;
}

void	execute(int cmd)
{
	if (cmd < 0 || cmd >= MAX_COMMAND)
		cmd = 0;
	commands[cmd].callback();
}

void	mainloop()
{
	int		cmd;

	while (1)
	{
		menu_help();
		if (get_user_input_int(&cmd) == FATAL_ERROR)
		{
			printf("Something went wrong!! Exiting\n");
			break;
		}
		if (cmd == MAX_COMMAND - 1)
			break;
		execute(cmd);
	}
}

void	lists_free()
{
	t_node *n;
	t_node *next;

	n = lists->first;
	while (n)
	{
		next = n->next;
		list_free((t_list**)&n->data, 0x0);
		free(n);
		n = next;
	}
	free(lists);
}

int main()
{
	lists = list_create();
	if (!lists)
	{
		fprintf(stderr, "Failed to allocate main list\n");
		return (ERROR);
	}
	init_folder();
	mainloop();
	lists_free();
	return 0;
}