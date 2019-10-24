#include "linked_list.h"

# define SIZE_BUFF 512
/*
int 	saved_stdout;
int 	out_pipe[2];
int 	ret;

void	pipe_to_buffer()
{
	saved_stdout = dup(1);
	if(pipe(out_pipe) != 0)
		exit(1);
	dup2(out_pipe[1], 1);
  	close(out_pipe[1]);
}

void	get_print(char *buffer)
{
	fflush(stdout);
	ret = read(out_pipe[0], buffer, SIZE_BUFF);
	buffer[ret] = 0;
	dup2(saved_stdout, STDOUT_FILENO);
}

void	test_create()
{
	t_list *l = list_create("Hello world\n");
	if (l)
		printf("test_create:: OK\n");
	else
		printf("test_create:: Failed\n");
	list_free(&l);
}

void	test_print()
{
	char	buffer[SIZE_BUFF + 1];
	
	bzero(buffer, SIZE_BUFF + 1);
	t_list *l = list_create("Hello world\n");
  	pipe_to_buffer();
	list_print(l);
	get_print(buffer);
	list_free(&l);
	if (strcmp(buffer, "Hello world\n") != 0)
		printf("test_print:: Failed\n");
	else
		printf("test_print:: Ok\n");
}

void	test_copy()
{
	char	buffer[SIZE_BUFF + 1];
	
	bzero(buffer, SIZE_BUFF + 1);
	t_list *lo = list_create("Hello world\n");
	t_list *lc = list_copy(lo);
  	pipe_to_buffer();
	list_print(lo);
	get_print(buffer);
	list_free(&lo);
	list_free(&lc);
	if (strcmp(buffer, "Hello world\n") != 0)
		printf("test_copy:: Failed\n");
	else
		printf("test_copy:: Ok\n");
}

void	test_concatenate()
{
	char	buffer[SIZE_BUFF + 1];
	
	bzero(buffer, SIZE_BUFF + 1);
	t_list *lo = list_create("Hello ");
	t_list *lc = list_create("world\n");
	list_concatenate(lo, lc);
  	pipe_to_buffer();
	list_print(lo);
	get_print(buffer);
	list_free(&lo);
	if (strcmp(buffer, "Hello world\n") != 0)
		printf("test_concatenate:: Failed\n");
	else
		printf("test_concatenate:: Ok\n");
}

void	test_insert()
{
	char	buffer[SIZE_BUFF + 1];
	
	bzero(buffer, SIZE_BUFF + 1);
	t_list *lo = list_create("Hello world\n");
	t_list *to_insert = list_create("");
	list_insert_list(lo, to_insert, 11);
  	pipe_to_buffer();
	list_print(lo);
	get_print(buffer);
	list_free(&lo);
	if (strcmp(buffer, "Hello world\n") != 0)
		printf("test_insert:: Failed got %s\n", buffer);
	else
		printf("test_insert:: Ok\n");
}


void	test_delete()
{
	char	buffer[SIZE_BUFF + 1];
	
	bzero(buffer, SIZE_BUFF + 1);
	t_list *lo = list_create("zeeeeee\n");
	list_delete(lo, "AAAAe\n");
  	pipe_to_buffer();
	list_print(lo);
	get_print(buffer);
	list_free(&lo);
	if (strcmp(buffer, "z") != 0)
		printf("test_delete:: Failed got %s\n", buffer);
	else
		printf("test_delete:: Ok\n");
}

void	test_search()
{
	char	buffer[SIZE_BUFF + 1];
	
	bzero(buffer, SIZE_BUFF + 1);
	t_list *lo = list_create("Hello world\n");
	t_array *arr = list_search(lo, "o");
	pipe_to_buffer();
	array_print(arr);
	get_print(buffer);
	list_free(&lo);
	if (strcmp(buffer, "5,8\n"))
		printf("test_search:: Failed got %s\n", buffer);
	else
		printf("test_search:: Ok\n");
}

void	test_replace()
{
	char	buffer[SIZE_BUFF + 1];
	
	bzero(buffer, SIZE_BUFF + 1);
	t_list *lo = list_create("Hello World?\n");
	list_replace(lo, "Hello World?\n", "23");
  	pipe_to_buffer();
	list_print(lo);
	get_print(buffer);
	list_free(&lo);
	if (strcmp(buffer, "23") != 0)
		printf("test_replace:: Failed got %s\n", buffer);
	else
		printf("test_replace:: Ok\n");
}

// void	test_import()
// {
// 	char	buffer[SIZE_BUFF + 1];
	
// 	t_list *lo = list_create("Hello world\n");
// 	t_array *arr = list_search(lo, "o");
//   	pipe_to_buffer();
// 	array_print(arr);
// 	get_print(buffer);
// 	list_free(&lo);
// 	if (strcmp(buffer, "z") != 0)
// 		printf("test_import:: Failed got %s\n", buffer);
// 	else
// 		printf("test_import:: Ok\n");
// }

// void	test_export()
// {
// 	char	buffer[SIZE_BUFF + 1];
	
// 	t_list *lo = list_create("zeeeeee\n");
// 	list_delete(lo, "AAAAe\n");
//   	pipe_to_buffer();
// 	list_print(lo);
// 	get_print(buffer);
// 	list_free(&lo);
// 	if (strcmp(buffer, "z") != 0)
// 		printf("test_export:: Failed got %s\n", buffer);
// 	else
// 		printf("test_export:: Ok\n");
// }


void	test()
{
	test_create();
	test_print();
	test_copy();
	test_concatenate();
	test_insert();
	test_delete();
	test_search();
	test_replace();
	// test_export();
	// test_import();
}*/