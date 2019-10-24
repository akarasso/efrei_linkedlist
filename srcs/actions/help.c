#include "linked_list.h"

int    menu_help()
{
    int i;

	i = 0;
	while (i < MAX_COMMAND)
	{
		printf("%d - %s - %s\n", i, commands[i].name, commands[i].desc);
		i++;
	}
	return SUCCESS;
}