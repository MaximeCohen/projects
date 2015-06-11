/*
** 42sh.h for 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Sun May 24 20:18:34 2015 leo lzfon
** Last update Sun May 24 23:14:13 2015 enzo resse
*/


#ifndef SH_H_
# define SH_H_

# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <ncurses/curses.h>
# include <term.h>

# define BUFFER_SIZE		8

# define MALLOC			"Malloc has failed\n"
# define SEPARATOR_CHARS	";|><&"
# define DELIM			" \t\n"

# define LOOP_TURN		10

typedef char t_bool;

typedef		enum s_separator
{
  SEMI_COL,
  PIPE,
  RD_RIGHT,
  DRD_RIGHT,
  RD_LEFT,
  DRD_LEFT,
  AND,
  OR,
  NOTHING
}		t_separator;

typedef		enum e_builtin
{
  EXIT,
  CD,
  ECKO,
  ENV,
  SETENV,
  UNSETENV,
  ALIAS,
  UNALIAS,
  NONE
}		t_builtin;

typedef			struct s_alias
{
  char			*name;
  char			*value;
  struct s_alias	*next;
}			t_alias;

typedef		struct s_hist
{
  char		*line;
  int		id;
  struct s_hist	*next;
  struct s_hist	*prev;
}		t_hist;

typedef		struct s_cmd
{
  char		**cmd;
  t_builtin	builtin;
  t_separator	separator;
  t_bool	file;
  struct s_cmd	*next;
  struct s_cmd	*prev;
}		t_cmd;

typedef		struct s_pipe
{
  int		pipefd[2];
  int		last_open;
  t_bool	file;
}		t_pipe;

typedef		struct s_exit
{
  t_bool	exit;
  int		value;
}		t_exit;

typedef			struct s_system
{
  char			**env;
  char			**path;
  t_hist		*history;
  t_cmd			*cmd;
  t_pipe		pipe;
  t_bool		lcmd_fail;
  t_exit		exit;
  t_alias		*alias;
  struct termios	t_attr;
  struct termios	s_attr;
}			t_system;

# include "redirection.h"
# include "autocomplete.h"

/*
**	generic functions
*/

void	my_putstr(char *);
char	*get_next_line(const int);
int	my_strlen(char *);
char	**my_str_to_wordtab(char *, int, int);
char	**my_str_to_wordtab2(char *, char *);
char	*my_str_concat(char *, char *, char);
char	**get_argv(char *, char *);

/*
**	signal
*/

void	handle_sig(int);

/*
**	list
*/

t_cmd	*put_in_cmd_list(char **, t_cmd *, char);
void	delete_link(t_cmd **);

/*
**	env & path
*/

char	save_env_and_path(t_system *, char **);
char	*my_getenv(char **, char *);

/*
**	parsing
*/

char	pars_line(t_system *, char *);

/*
**	determine
*/

char	determine_cmd(t_system *);

/*
**	free
*/

void	free_cmd(t_cmd *);
void	free_all(t_system *);

/*
**	Generics
*/

void	aff_env(t_system *);
void	put_error(char *);
void	my_putchar(char);
void	aff_path(t_system *);
char	*my_strdog(char *, char *);
void	*my_realloc(void *, int);
int	my_getnbr(char *);
int	my_strlen(char *);

int	builtin_cdhome(char ***);
int	builtin_setenv(char ***, char *, char *);
int	wordtab_len(char **);
int	set_pwd(char ***, char *);
int	count_word(char *, char *);

/*
**	History
*/

void	save_line(t_system *, char *);
void	delete_last(t_hist *);
void	aff_history(t_hist *);
void	add_elem(t_hist *, char *, int);
void	reset_history(t_system *);

/*
**	Alias
*/

void	save_alias(t_system *);
char	*get_home(char **);
void	process_line(char *);
int	add_alias_tolist(t_alias **, char *, char *);
int	dell_alias_tolist(t_alias **, char *);
void	free_select_alias(t_alias *);

/*
**	Termcaps
*/

void	clean_line(char *);
char	*klear_screen(t_system *, char *);
char	set_termcaps(t_system *);
char	unset_termcaps(t_system *);

/*
**	Cmd line
*/

char	without_termcaps(t_system *);
char	get_cmd_line(t_system *);
char	is_arrow(char *);
char	*manage_arrow(t_system *, char *, char *);
char	*decrease_line(t_system *, char *);
char	*append_to_line(char *, char *);
char	*do_echo_pipe(t_system *, char *, char *);
char	is_echo_pipe(char *);
char	check_tabulation(char *);
char	check_ctr_l(char *);
char	check_backspace(char *);
char	is_special_case(char *);
char	send_line(t_system *, char **);

char	*switch_line(t_system *, char *);
char	is_separator_char(char);
char	*my_globing(char *);
void	reset_line(t_system *, char **);
char	check_separators(t_system *);

/*
**	Replace
*/

char	*replace_line(char *, char *, char *, int);
char	*begin_of_line(char *, int);
void	free_bl(char *, char *);
char	*replace_cmd(t_system *, char *, int, int);
char	*check_alias(t_alias *, char *);
char	*get_begin(char *);
char	*get_end(char *);
char	*get_mid(char *);
char	is_dollar(char *);
char	*check_dollar(char **, char *);
char	**replace_between_separators(char *, int *);
char	*replace_dollar(t_system *, char **, char *, char *);
void	free_dollar(char *, char *, char *);

/*
**	Conf file
*/

char	process_conf_file(t_system *);

/*
**      aff prompt
*/

t_system	*get_sys(t_system *);
int		aff_prompt(t_system *);

#endif /* !SH_H_ */
