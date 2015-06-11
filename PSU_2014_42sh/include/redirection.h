/*
** redirection.h for 42sh in /home/resse_e/save/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Fri May 22 21:15:42 2015 enzo resse
** Last update Sat May 23 17:02:47 2015 enzo resse
*/

#ifndef REDIRECTION_H_
# define REDIRECTION_H_

# define C_RIGHT (S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP)
# define C_TRUNC (O_TRUNC | O_CREAT)
# define C_APPEND (O_APPEND | O_CREAT)

int	ctrl_rd(t_system *);
int	ctrl_exe(t_system *);
int	ctrl_param(t_system *, int *);
int	controle(t_system *);

int	simple_rd(t_system *, int *);
int	rd_and_exe(t_system *, int *);

int	close_fd(int);
int	my_pipe(t_system *sys);

int	broken_dup(t_system *, int);
int	pipe_connected(t_system *, int *, int *);
int	pipe_disconnected(t_system *sys, int *, int *);
int	use_builtin(t_system *);

int	init_spr(t_system *);

int	check_pipe_buffer(t_system *);
int     check_pipeout_buffer(t_system *);
int	son(t_system *);
int	dady(t_system *, int);
int	use_exe(t_system *);

void	set_pipe(t_system *);
int	reset_pipe(t_system *);
int	init_pipe(t_system *);
int	clean_fd(t_system *);

int	rdr_checkout(t_system *);
int	rdl_checkout(t_system *);

int	rd_right(t_system *);
int	rdr_open(t_system *, int *);

int	and(t_system *);
int	or(t_system *);
void	operator_delete(t_system *);

int	drd_right(t_system *);

int	rd_left(t_system *);
int	rdl_open(t_system *);

int	drd_left(t_system *);
int	drdl_open(t_system *);

int	sys_error(int);

int	fail(void);
int	nothing(void);
int	bad_fd(void);
int	fd_stoped(void);
int	fd_limited(void);

int	my_exit(t_system *);
int     my_cd(t_system *);
int     my_echo(t_system *);
int     my_env(t_system *);
int     my_setenv(t_system *);
int     my_unsetenv(t_system *);
int	my_alias(t_system *);
int	my_unalias(t_system *);

#endif /* !REDIRECTION_H_ */
