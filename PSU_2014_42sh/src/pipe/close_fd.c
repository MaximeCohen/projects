/*
** close_fd.c for 42sh in /home/resse_e/rendu/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Fri May  8 15:41:40 2015 enzo resse
** Last update Fri May 22 22:36:48 2015 enzo resse
*/

#include "42sh.h"

int	close_fd(int fd)
{
  errno = 0;
  if (fd > 2)
    {
      if (close(fd) < 0)
	{
	  if (errno == EBADF)
	    return (2);
	  else if (errno == EINTR)
	    return (3);
	  else
	    return (0 * printf("error in close\n"));
	}
    }
  return (1);
}

int	my_pipe(t_system *sys)
{
  errno = 0;
  if (pipe(sys->pipe.pipefd) == -1)
    {
      if (errno == ENFILE)
	return (4);
      else
	return (0 * printf("error in pipe\n"));
    }
  return (1);
}
