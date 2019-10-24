#include "linked_list.h"

void	insert_to_fd(int index, void *node, void *data)
{
	int			*fd;
	t_char_node	*cnode;

	(void)index;
	fd = (int*)data;
	printf("INSERT %d\n", *fd);
	cnode = (t_char_node*)node;
	write(*fd, &cnode->data, 1);
}

int		menu_export_open_file(char *filepath, int *fd)
{
	*fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd < 0) {
		perror("fd");
    	return FATAL_ERROR;
	}
	if (write(*fd, "", 0) < 0)
	{
		if (close(*fd) < 0) {
			perror("close fd:");
			return FATAL_ERROR;
		}
		perror("write");
		return FATAL_ERROR;
	}
	return SUCCESS;
}

int		menu_export()
{
	t_node	*string;
	char	*filepath;
	int		index_string;
	int		fd;

	if (get_user_input_index(&index_string, "Please enter index from string to export ") != SUCCESS)
		return FATAL_ERROR;
	string = list_get_index(lists, index_string);
	if (!string) {
		printf("Failed to get string from index %d\n", index_string);
		return ERROR;
	}
	printf("Please enter namefile:\n");
	if (get_user_input_path(&filepath) != SUCCESS)
		return FATAL_ERROR;
	if (menu_export_open_file(filepath, &fd) != SUCCESS)
		return FATAL_ERROR;
	list_foreach(string->data, insert_to_fd, &fd);
	if (close(fd) < 0) {
		perror("close fd:");
		return FATAL_ERROR;
	}
	return SUCCESS;
}