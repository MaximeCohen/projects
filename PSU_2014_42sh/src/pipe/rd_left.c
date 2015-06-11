/*
** rd_left.c for 42sh in /home/resse_e/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Wed May 13 10:06:49 2015 enzo resse
** Last update Fri May 22 22:41:35 2015 enzo resse
*/

#include "42sh.h"

int	rd_left(t_system *sys)
{
  int	checkout;
  t_cmd	*tmp;

  tmp = sys->cmd->prev;
  reset_pipe(sys);
  checkout = rdl_open(sys);
  if (checkout > 0)
    checkout = rdl_checkout(sys);
  sys->cmd = tmp;
  return (checkout);
}

int	rdl_open(t_system *sys)
{
  int	fd;

  fd = 0;
  delete_link(&(sys->cmd));
  if (sys->cmd == NULL)
    return (0 * printf("error in command line \n"));
  if ((fd = open(sys->cmd->cmd[0], O_RDONLY)) < 0)
    {
      delete_link(&(sys->cmd));
      return (0 * printf("No such file or directory\n"));
    }
  delete_link(&(sys->cmd));
  if (sys->pipe.last_open > 0)
    {
      if (sys_error(close_fd(sys->pipe.last_open)) != 1)
	return (0);
    }
  sys->pipe.last_open = fd;
  return (1);
}
