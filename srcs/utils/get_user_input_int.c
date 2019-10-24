#include "linked_list.h"

int		get_user_input_int(int *input)
{
	char	*str;

	if (get_user_input_string(&str) == ERROR)
		return ERROR;
	*input = atoi(str);
	free(str);
	return SUCCESS;
}

int		get_user_input_position(int *input, t_list *list, char *print)
{
	char	*str;

	printf("%s [0;%d]\n", print, list->len);
	if (get_user_input_string(&str) == ERROR)
		return ERROR;
	*input = atoi(str);
	if (*input < 0)
	{
		printf("You enter bad input. Default input 0 was taken.\n");
		*input = 0;
	}
	free(str);
	return SUCCESS;
}

int		get_user_input_index(int *input, char *print)
{
	char	*str;

	printf("%s [0;%d[\n", print, lists->len);
	if (get_user_input_string(&str) == ERROR)
		return ERROR;
	*input = atoi(str);
	if (*input < 0 || *input >= lists->len)
	{
		printf("You enter bad input. Default input 0 was taken.\n");
		*input = 0;
	}
	free(str);
	return SUCCESS;
}
