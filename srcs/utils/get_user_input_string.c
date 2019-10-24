#include "linked_list.h"

void	strdel(char **s)
{
	if (s && *s)
	{
		free(s);
		*s = 0x0;
	}
}

int		get_user_input_string(char **input)
{
	char	buffer[SIZE_BUFF + 1];
	int		ret;
	int		len;

	*input = strdup("");
	len = 0;

	while ((ret = read(0, buffer, SIZE_BUFF)) != 0)
	{
		buffer[ret] = 0;
		if (ret < 0)
		{
			strdel(input);
			return ERROR;
		}
		*input = realloc((*input), len + ret + 1);
		strcpy(&(*input)[len], buffer);
		(*input)[len + ret] = 0;
		len += ret;
		if (ret < SIZE_BUFF)
		{
			(*input)[len - 1] = 0; // Delete last \n at end of input
			break;
		}
	}
	return SUCCESS;
}

int		get_user_input_path(char **input)
{
	char	buffer[SIZE_BUFF + 1];
	int		ret;
	int		len;

	*input = strdup("./data/");
	len = 7;
	while ((ret = read(0, buffer, SIZE_BUFF)) != 0)
	{
		buffer[ret] = 0;
		if (ret < 0)
		{
			strdel(input);
			return ERROR;
		}
		*input = realloc((*input), len + ret + 1);
		strcpy(&(*input)[len], buffer);
		(*input)[len + ret] = 0;
		len += ret;
		if (ret < SIZE_BUFF)
		{
			(*input)[len - 1] = 0; // Delete last \n at end of input
			break;
		}
	}
	return SUCCESS;
}