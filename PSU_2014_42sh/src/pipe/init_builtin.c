/*
** init_builtin.c for 42sh in /home/resse_e/save/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Fri May 22 21:15:10 2015 enzo resse
** Last update Sun May 24 20:26:56 2015 enzo resse
*/

#include "42sh.h"

int	broken_dup(t_system *sys, int dup_broke)
{
  int	output[2];

  if (dup_broke == 0 || dup_broke == 2)
    {
      output[0] = dup2(0, sys->pipe.last_open);
      if (output[0] >= 0)
	printf("standard intput repared\n");
      else
	printf("can't repared standard intput\n");
    }
  if (dup_broke == 0 || dup_broke == 2)
    {
      output[1] = dup2(1, sys->pipe.pipefd[1]);
      if (output[1] >= 0)
	printf("standard output repared\n");
      else
        printf("can't repared standard output\n");
    }
  return (0);
}

int	pipe_connected(t_system *sys, int *last_in, int *last_out)
{
  if (sys->pipe.last_open > 0)
    {
      *last_in = dup(0);
      if (close(0) < 0)
	return (0);
      dup(sys->pipe.last_open);
      if (sys->pipe.pipefd[1] != 0)
	{
	  *last_out = dup(1);
	  if (close(1) < 0)
	    return (0);
	  dup(sys->pipe.pipefd[1]);
	}
    }
  return (1);
}

int	pipe_disconnected(t_system *sys, int *last_in, int *last_out)
{
  if (sys->pipe.last_open > 0 || *last_in != -1)
    {
      if (close(0) < 0)
	return (0);
      if (dup(*last_in) < 0)
	return (0);
      if (sys_error(close_fd(sys->pipe.last_open)) != 1)
	return (0);
      if (sys_error(close_fd(sys->pipe.pipefd[1])) != 1)
	return (0);
      sys->pipe.pipefd[1] = 0;
      sys->pipe.last_open = sys->pipe.pipefd[0];
      sys->pipe.pipefd[0] = 0;
      if (*last_out != -1)
	{
	  if (close(1) < 0)
	    return (0);
	  if (dup(*last_out) < 0)
	    return (0);
	}
    }
  return (1);
}

int		use_builtin(t_system *sys)
{
  static int	(*fct[])(t_system *sys) =
    {
      &my_exit,
      &my_cd,
      &my_echo,
      &my_env,
      &my_setenv,
      &my_unsetenv,
      &my_alias,
      &my_unalias,
      NULL
    };
  int		check_output;
  int		last_output;
  int		last_input;

  last_output = -1;
  last_input = -1;
  if (pipe_connected(sys, &last_input, &last_output) == 0)
    return (0);
  check_output = fct[sys->cmd->builtin](sys);
  if (pipe_disconnected(sys, &last_input, &last_output) == 0)
    return (0);
  return (check_output);
}
