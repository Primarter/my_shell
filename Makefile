##
## EPITECH PROJECT, 2019
## new_project
## File description:
## Makefile
##

RM			=	rm -rf
CC			=	gcc
CFLAGS		=	-W -Wall -Wextra -Iinclude/
LDFLAGS		=	-L./ -lmy
TEST_LDFLAGS=	-lcriterion --coverage -L./ -lmy
SRC			=	src/main.c									\
				src/env/handle_env.c						\
				src/env/handle_list.c						\
				src/env/init_env.c							\
				src/env/my_linked_list.c					\
				src/env/parse_env.c							\
				src/env/set_default_values.c				\
				src/env/set_list.c							\
				src/env/switch_list.c						\
				src/exec/action_select.c					\
				src/exec/cd.c								\
				src/exec/commands.c							\
				src/exec/parsing.c							\
				src/exec/unsetenv.c							\
				src/line_command_exec/execute_line.c		\
				src/line_command_exec/parse_cmd_line.c		\
				src/line_command_exec/parse_redirection.c	\
				src/misc/help.c								\
				src/misc/match_str.c						\
				src/misc/immutable_test.c
TEST_SRC	=	tests/test.c
OBJ			=	$(SRC:.c=.o)
TEST_OBJ	=	$(TEST_SRC:.c=.o)
NAME		=	mysh
TEST_NAME	=	./unit-tests

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/ > /dev/null
	$(CC) -o $@ $^ $(LDFLAGS)

$(TEST_NAME): $(TEST_OBJ)
	make -C ./lib/my/ > /dev/null
	$(CC) -o $@ $^ $(TEST_LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(BOOTSTRAP_OBJ)
	$(RM) libmy.a
	$(RM) $(TEST_OBJ)
	$(RM) $(TEST_NAME)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ:.o=.gcda)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BOOTSTRAP_NAME)
	$(RM) vgcore.*
	$(RM) log

re: fclean all

tests_run: $(TEST_NAME)
	$(TEST_NAME); gcovr