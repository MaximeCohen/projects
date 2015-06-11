/*
** rd_right.c for 42sh in /home/resse_e/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Wed May 13 10:03:09 2015 enzo resse
** Last update Sat May 23 15:27:34 2015 enzo resse
*/

# include "42sh.h"

int	rd_right(t_system *sys)
{
  t_cmd	*tmp;
  int	fd;

  tmp = sys->cmd->prev;
  fd = 0;
  delete_link(&(sys->cmd));
  if (sys->cmd == NULL)
    return (0 * printf("error in command line \n"));
  sys->cmd->separator = 2;
  if (rdr_open(sys, &fd) == 0)
    return (0);
  delete_link(&(sys->cmd));
  if (sys_error(close_fd(sys->pipe.pipefd[1])) != 1)
    return (0);
  sys->pipe.pipefd[0] = 0;
  sys->pipe.pipefd[1] = fd;
  if (sys->pipe.last_open == 0)
    sys->pipe.last_open = 1;
  while (sys->cmd != NULL &&
         (sys->cmd->separator == 2 || sys->cmd->separator == 3))
    if (rdr_checkout(sys) == 0)
      return (0);
  sys->cmd = tmp;
  sys->pipe.file = true;
  return (1);
}

int	rdr_open(t_system *sys, int *fd)
{
  if (sys->cmd->separator == 2)
    {
      if ((*fd = open(sys->cmd->cmd[0], O_WRONLY | C_TRUNC, C_RIGHT)) < 0)
        {
          delete_link(&(sys->cmd));
          return (0 * printf("error while creating or openning file\n"));
        }
    }
  else
    {
      if ((*fd = open(sys->cmd->cmd[0], O_WRONLY | C_APPEND, C_RIGHT)) < 0)
        {
          delete_link(&(sys->cmd));
          return (0 * printf("error while creating or openning file\n"));
        }
    }
  return (1);
}
