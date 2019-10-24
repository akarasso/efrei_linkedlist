#ifndef LINKED_LIST_H // Could be replace by pragma once
# define LINKED_LIST_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

# define FATAL_ERROR 2
# define ERROR 1
# define SUCCESS 0

# define SIZE_BUFF 512
# define MAX_COMMAND 12

typedef struct s_char_node t_char_node;
typedef struct s_node t_node;
typedef struct s_list t_list;
typedef struct s_cmd t_cmd;

struct s_cmd
{
	int			(*callback)();
	char		*name;
	char		*desc;
};

struct s_list
{
	t_node	*first;
	t_node	*last;
	int		len;
};

struct s_node
{
	t_node	*next;
	t_node	*prev;
	void	*data;
};

struct s_char_node
{
	t_char_node	*next;
	t_char_node	*prev;
	char		data;
};

extern t_cmd	commands[MAX_COMMAND];
extern t_list	*lists;

void	test();

/*
**	List
*/

t_list			*list_map(t_list *origin, void *func_copy_node(t_node *), void func_delete_node(t_node *));
t_list			*list_create();
t_node			*node_create(void *data);
void			*list_get(t_list *list, void *addr);
void			*list_get_and_delete_node(t_list *list, void *addr, void *func_to_free(void*));
void			*list_get_index(t_list *list, int index);
void			*list_get_and_remove_index(t_list *list, int index);
void			*list_get_and_remove_node(t_list *list, void *addr);
int				list_insert_list(t_list *list_dest, t_list *list_src, int index);
void			list_filter(t_list *l, int (*filter_func)(t_node*, void*), void *data);
void			list_foreach(t_list *l, void (*exec_func)(int, void*, void *), void *data);
void			list_free(t_list **l, void func_free_node(t_node *));
void			list_pushback(t_list *list_dest, t_node *node);
//int				list_insert(t_list *list_dest, t_list *list_src, int index);

/*
** Loop function
*/

int				get_user_input_int(int *input);
int				get_user_input_string(char **input);
int				get_user_input_index(int *input, char *str);
int				get_user_input_position(int *input, t_list *list, char *print);
int				get_user_input_path(char **input);


void			*node_create_char(char data);
int				list_char_create(t_list **new_char_list);
void			clear_stdin();
void			mainloop();
int				menu_help();
int				menu_concat();
int    			menu_add_entrie();
int				menu_delete_char();
int				menu_copy();
int				print_entries();
void			print_header();
void			print_string(int index, void *node, void *data);
int				menu_insert();
int				menu_search();
int				menu_replace();
int				menu_import();
int				menu_export();

int				check_match_string(t_char_node *cnode, char *str);

#endif