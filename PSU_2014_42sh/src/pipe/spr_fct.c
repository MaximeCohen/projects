/*
** spr_fct.c for 42sh in /home/resse_e/rendu/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Fri May  8 14:46:45 2015 enzo resse
** Last update Sat May 23 14:30:19 2015 enzo resse
*/

#include "42sh.h"

void	set_pipe(t_system *sys)
{
  sys->pipe.pipefd[0] = 0;
  sys->pipe.pipefd[1] = 0;
  sys->pipe.last_open = 0;
  sys->pipe.file = false;
}

int	reset_pipe(t_system *sys)
{
  if (sys->pipe.last_open != 0)
    {
      if (sys_error(close_fd(sys->pipe.last_open)) != 1)
	return (0);
      if (sys_error(close_fd(sys->pipe.pipefd[0])) != 1)
	return (0);
      if (sys_error(close_fd(sys->pipe.pipefd[1])) != 1)
        return (0);
      set_pipe(sys);
    }
  return (1);
}

int	init_pipe(t_system *sys)
{
  sys->pipe.file = false;
  if (sys->pipe.last_open == 0)
    sys->pipe.last_open = 1;
  if (pipe(sys->pipe.pipefd) < 0)
    return (0);
  return (1);
}

int	clean_fd(t_system *sys)
{
  int	a;
  int	pipefd[2];

  a = 3;
  set_pipe(sys);
  pipe(pipefd);
  while (a != pipefd[1] + 1)
    {
      if (sys_error(close_fd(a)) != 1)
        return (0);
      ++a;
    }
  return (1);
}
