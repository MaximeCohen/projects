##
## Makefile for 42sh in /home/resse_e/save/PSU_2014_42sh
## 
## Made by enzo resse
## Login   <resse_e@epitech.net>
## 
## Started on  Fri May 22 21:16:07 2015 enzo resse
## Last update Sun May 24 23:28:51 2015 Florian Huet
##

COLOR		= \x1b[32;01m

COLOR_OFF	= \x1b[0m

PROG_OK		= $(COLOR)[Program compiled]$(COLOR_OFF)

ALL_CLEAN	= $(COLOR)[Directory cleaned!]$(COLOR_OFF)

CC		= gcc

RM		= rm -f

NAME		= 42sh

SRC		= src/main.c \
		  src/signal.c \
		  src/list.c \
		  src/pars.c \
		  src/free.c \
		  src/save_data.c \
		  src/determine.c \
		  src/get_argv.c \
		  src/termcaps.c \
		  src/get_cmd_line.c \
		  src/arrow.c \
		  src/manage_line.c \
		  src/check_buffer.c \
		  src/do_echo_pipe.c \
		  src/globing.c \
		  src/without_termcaps.c \
		  src/switch_line.c \
		  src/pipe/close_fd.c \
		  src/pipe/controle.c \
		  src/pipe/ctrl_param.c \
		  src/pipe/init_builtin.c \
		  src/pipe/init_spr.c \
		  src/pipe/new_fork.c \
		  src/pipe/spr_fct2.c \
		  src/pipe/spr_fct.c \
		  src/pipe/sys_error.c \
		  src/pipe/sys_error_fct2.c \
		  src/pipe/sys_error_fct.c \
		  src/pipe/rd_right.c \
		  src/pipe/drd_right.c \
		  src/pipe/rd_left.c \
		  src/pipe/drd_left.c \
		  src/pipe/operateur.c \
		  src/builtins/cd.c \
		  src/builtins/copy_env.c \
		  src/builtins/echo.c \
		  src/builtins/env.c \
		  src/builtins/exit.c \
		  src/builtins/my_getenv.c \
		  src/builtins/my_strdog.c \
		  src/builtins/setenv.c \
		  src/builtins/set_pwd.c \
		  src/builtins/unsetenv.c \
		  src/builtins/wordtab_len.c \
		  src/history.c \
		  src/alias.c \
		  src/unalias.c \
		  src/alias_list.c \
		  src/autocomplete/autocomplete.c \
		  src/autocomplete/autocomp_cut.c \
		  src/autocomplete/frees.c \
		  src/replace_line.c \
		  src/replace_cmd.c \
		  src/get_dollar.c \
		  src/replace_cmd_generic.c \
		  src/conf_file.c \
		  src/prompt.c \

LIB		= lib/get_next_line.c \
		  lib/str.c \
		  lib/generic.c \
		  lib/my_str_to_wordtab.c \
		  lib/my_str_to_wordtab2.c \
		  lib/my_getnbr.c

OBJ		= $(SRC:.c=.o) \
		  $(LIB:.c=.o)

CFLAGS		= -I./include/ -lncurses -W -Wall -Wextra

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
		@echo -e "$(PROG_OK)"

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		@echo -e "$(ALL_CLEAN)"

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
