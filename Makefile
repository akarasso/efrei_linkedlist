CC	= gcc

CFLAGS	= -g3 -Wall -Werror -Wextra

NAME	= linked

HEADERS	= ./includes

SOURCES	= \
	./srcs/list/create.c \
	./srcs/list/filter.c \
	./srcs/list/foreach.c \
	./srcs/list/free.c \
	./srcs/list/get.c \
	./srcs/list/get_and_delete.c \
	./srcs/list/get_and_remove.c \
	./srcs/list/get_and_remove_index.c \
	./srcs/list/get_index.c \
	./srcs/list/insert.c \
	./srcs/list/map.c \
	./srcs/list/pushback.c \
	./srcs/utils/get_user_input_string.c \
	./srcs/utils/get_user_input_int.c \
	./srcs/actions/concatenate.c \
	./srcs/actions/copy.c \
	./srcs/actions/create.c \
	./srcs/actions/export.c \
	./srcs/actions/filter_char.c \
	./srcs/actions/help.c \
	./srcs/actions/import.c \
	./srcs/actions/insert.c \
	./srcs/actions/print.c \
	./srcs/actions/replace.c \
	./srcs/actions/search.c \
	./srcs/global.c \
	./srcs/test.c \
	./srcs/main.c
	
OBJ	= $(SOURCES:.c=.o)

HEADER_LIST	= $(addprefix -I,$(HEADERS))

all	: $(NAME)

%.o	: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADER_LIST) -c -o $@ $<

$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) $(HEADER_LIST) -o $(NAME) $(OBJ)

clean	:
	rm -f $(OBJ)

re	: fclean all

fclean	: clean
	rm -f $(NAME)
