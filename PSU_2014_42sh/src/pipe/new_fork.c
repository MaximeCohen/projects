/*
** new_fork.c for 42sh in /home/resse_e/rendu/PSU_2014_42sh/src/pipe
**
** Made by enzo resse
** Login   <resse_e@epitech.net>
**
** Started on  Fri May  8 15:01:35 2015 enzo resse
** Last update Sun May 24 23:04:00 2015 enzo resse
*/

#include "42sh.h"

int	check_pipeout_buffer(t_system *sys)
{
  int	checkout;
  char	str[65001];
  int	pipefd[2];

  if (sys->pipe.pipefd[1] > 0 && sys->pipe.file == false &&
      sys->lcmd_fail == true)
    {
      printf("grose pute\n");
      if ((checkout = read(sys->pipe.pipefd[0], str, 65000)) >= 64999)
        return (0 * printf("error in pipe\n"));
      if (checkout == -1)
        return (0 * printf("error in read\n"));
      if (pipe(pipefd) < 0)
        return (0);
      if (write(pipefd[1], str, checkout) < 0)
        return (0 * printf("error in write\n"));
      close(sys->pipe.pipefd[1]);
      close(sys->pipe.pipefd[0]);
      sys->pipe.pipefd[0] = pipefd[0];
      sys->pipe.pipefd[1] = pipefd[1];
    }
  return (1);
}

int	son(t_system *sys)
{
  pid_t	pid;

  pid = getpid();
  if (sys->cmd->cmd != NULL)
  if (sys->pipe.last_open != 0)
    {
      if (dup2(sys->pipe.last_open, 0) < 0)
	kill(pid, SIGKILL);
      if (sys->pipe.pipefd[1] != 0)
	if (dup2(sys->pipe.pipefd[1], 1) < 0)
	  kill(pid, SIGKILL);
      if (sys_error(close_fd(sys->pipe.pipefd[0])) != 1)
	kill(pid, SIGKILL);
    }
  if (execve(sys->cmd->cmd[0], sys->cmd->cmd, sys->env) == -1)
    kill(pid, SIGKILL);
  kill(pid, SIGKILL);
  return (1);
}

int	dady(t_system *sys, int pid)
{
  int	a;

  if (check_pipeout_buffer(sys) == 0)
    {
      printf("segmentation fault\n");
      kill(pid, SIGSEGV);
    }
  wait(&a);
  if (sys->pipe.last_open > 0)
    {
      if (sys_error(close_fd(sys->pipe.last_open)) != 1)
	return (0);
      sys->pipe.last_open = sys->pipe.pipefd[0];
      sys->pipe.pipefd[0] = 0;
      if (sys_error(close_fd(sys->pipe.pipefd[1])) != 1)
	return (0);
      sys->pipe.pipefd[1] = 0;
    }
  if (WTERMSIG(a) == 11)
    return (0 *printf("Segmentation fault\n"));
  else if (a != 0)
    return (0 *printf("error in new proces\n"));
  return (1);
}

int	use_exe(t_system *sys)
{
  int	pid;

  if (sys->cmd->file == true)
    return (0 * printf("can't execute\n"));
  if ((pid = fork()) == -1)
    return (reset_pipe(sys));
  if (pid == 0)
    {
      if (son(sys) == 0)
	return (0);
    }
  else
    if (dady(sys, pid) == 0)
      return (0);
  return (1);
}
