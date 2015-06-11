/*
** spr_fct2.c for 42sh in /home/resse_e/rendu/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Sun May 10 11:57:59 2015 enzo resse
** Last update Fri May 22 22:42:02 2015 enzo resse
*/

#include "42sh.h"

int	rdr_checkout(t_system *sys)
{
  int	prev;
  int	fd;

  fd = 0;
  prev = sys->cmd->separator;
  delete_link(&(sys->cmd));
  if (sys->cmd == NULL)
    return (0 * printf("error in command line \n"));
  sys->cmd->separator = prev;
  if (rdr_open(sys, &fd) == 0)
    return (0);
  delete_link(&(sys->cmd));
  if (sys_error(close_fd(sys->pipe.pipefd[1])) != 1)
    return (0);
  sys->pipe.pipefd[1] = fd;
  return (1);
}

int	rdl_checkout(t_system *sys)
{
  while (sys->cmd != NULL &&
      (sys->cmd->separator == 4 || sys->cmd->separator == 5))
    {
      if (sys->cmd->separator == 4)
	{
	  if (rdl_open(sys) == 0)
	    return (0);
	}
      else
	{
	  if (drdl_open(sys) == 0)
	    return (0);
	}
    }
  if (sys->cmd != NULL && (sys->cmd->separator < 4 && sys->cmd->separator > 0))
    {
      if (sys->cmd->separator == 1)
	{
	  init_spr(sys);
	  delete_link(&(sys->cmd));
	}
      else
	init_spr(sys);
    }
  return (1);
}
