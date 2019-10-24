#include "linked_list.h"

int		menu_import_open_file(char *filepath, int *fd)
{
	char	buffer[1];

	*fd = open(filepath, O_RDONLY, 0644);
	if (*fd < 0) {
    	perror("fd");
    	return FATAL_ERROR;
	}
	if (read(*fd, buffer, 0) < 0)
	{
		perror("read");
		return FATAL_ERROR;
	}
	return SUCCESS;
}

int		import_char_from_str(t_list *list, char *str)
{
	t_char_node *node;

	while (*str)
	{
		node = node_create_char(*str);
		if (!node)
			return FATAL_ERROR;
		list_pushback(list, (t_node*)node);
		str++;
	}
	return SUCCESS;
}

int		menu_import_read_all(int fd, t_list *new_char_list)
{
	char	buffer[512 + 1];
	int		ret;

	while ((ret = read(fd, buffer, 512)) > 0)
	{
		buffer[ret] = 0;
		if (import_char_from_str(new_char_list, buffer) != SUCCESS)
			return FATAL_ERROR;
	}
	return SUCCESS;
}

int		menu_import()
{
	t_list	*new_char_list;
	t_node	*new_node;
	char	*filepath;
	int		fd;

	printf("Please enter namefile:\n");
	if (get_user_input_path(&filepath) != SUCCESS)
		return FATAL_ERROR;
	if (menu_import_open_file(filepath, &fd) != SUCCESS)
	{
		free(filepath);
		return ERROR;
	}
	new_char_list = list_create();
	if (!new_char_list)
	{
		free(filepath);
		printf("Failed to allocate new char list\n");
		return FATAL_ERROR;
	}
	if (menu_import_read_all(fd, new_char_list))
	{
		free(filepath);
		return FATAL_ERROR;	
	}
	new_node = node_create(new_char_list);
	if (!new_char_list)
	{
		free(filepath);
		list_free(&new_char_list, 0x0);
		printf("Failed to allocate new char list\n");
		return FATAL_ERROR;
	}
	list_pushback(lists, new_node);
	free(filepath);
	if (close(fd) < 0) {
		perror("close fd");
    	return FATAL_ERROR;
	}
	return SUCCESS;
}