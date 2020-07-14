##
## EPITECH PROJECT, 2020
## minishell2
## File description:
## Makefile
##

NAME	=	mysh

SRC	=	src/main.c		\
		src/copy_env.c		\
		src/minishell.c		\
		src/check_buff.c	\
		src/check_line.c	\
		src/clean_that.c	\
		src/get_buffs.c		\
		src/get_args.c		\
		src/check_command.c	\
		src/my_exit.c		\
		src/my_env.c		\
		src/my_setenv.c		\
		src/my_unsetenv.c	\
		src/my_cd.c		\
		src/exec_bin.c		\
		src/get_path.c		\
		src/exec_prog.c		\
		$(wildcard util/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wextra -Wall

CPPFLAGS=	-I./include/

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS)

debug	:	CFLAGS += -g
debug	:	re

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)		\
		rm -f *#                \
		rm -f src/*#            \
		rm -f include/*#        \
		rm -f *~                \
		rm -f src/*~            \
		rm -f include/*~        \
		rm -f *.gcda            \
		rm -f *.gcno            \

re	:	fclean all

.PHONY	:	all debug clean fclean re
