/*
** drd_left.c for 42sh in /home/resse_e/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Fri May 15 09:17:31 2015 enzo resse
** Last update Fri May 22 22:39:17 2015 enzo resse
*/

#include "42sh.h"

int	drd_left(t_system *sys)
{
  int	checkout;
  t_cmd	*tmp;

  tmp = sys->cmd->prev;
  checkout = drdl_open(sys);
  if (checkout > 0)
    checkout = rdl_checkout(sys);
  sys->cmd = tmp;
  return (checkout);
}

int	drdl_open(t_system *sys)
{
  char	*line;

  delete_link(&(sys->cmd));
  if (sys->cmd == NULL)
    return (0 * printf("error in command line \n"));
  reset_pipe(sys);
  init_pipe(sys);
  while (strcmp((line = get_next_line(0)), sys->cmd->cmd[0]) != 0)
    {
      write(sys->pipe.pipefd[1], line, strlen(line));
      write(sys->pipe.pipefd[1], "\n", 1);
      free(line);
    }
  write(sys->pipe.pipefd[1], "\0", 1);
  sys->pipe.last_open = sys->pipe.pipefd[0];
  if (sys_error(close_fd(sys->pipe.pipefd[1])) != 1)
    return (0);
  sys->pipe.pipefd[1] = 0;
  delete_link(&(sys->cmd));
  return (1);
}
