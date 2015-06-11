/*
** controle.c for 42sh in /home/resse_e/rendu/PSU_2014_42sh/src/pipe
**
** Made by enzo resse
** Login   <resse_e@epitech.net>
**
** Started on  Thu May  7 21:33:55 2015 enzo resse
** Last update Sun May 24 22:30:25 2015 leo lzfon
*/

#include "42sh.h"

int		ctrl_rd(t_system *sys)
{
  t_cmd		*tmp;
  int		nb_next;
  unsigned int	last_rd;

  nb_next = 2;
  tmp = sys->cmd;
  if (sys->cmd->next != NULL)
    {
      sys->cmd = sys->cmd->next;
      if (sys->cmd->cmd != NULL)
	return (0 * printf("error: multi exe\n"));
      last_rd = sys->cmd->separator;
      if (sys->cmd->separator != NOTHING)
	{
	  sys->lcmd_fail = false;
	  if (init_spr(sys) == 0)
	    sys->lcmd_fail = true;
	}
      sys->cmd = tmp;
      if (tmp->next != NULL && last_rd != sys->cmd->next->separator)
	nb_next = 1;
    }
  return (nb_next);
}

int	ctrl_exe(t_system *sys)
{
  if (sys->cmd->builtin != NONE)
    {
      if (use_builtin(sys) == 0)
	return (0);
    }
  else
    {
      if (use_exe(sys) == 0)
	return (0);
    }
  return (1);
}

int	ctrl_param(t_system *sys, int *last_cmd)
{
  if (sys->cmd->cmd == NULL)
    {
      if (simple_rd(sys, last_cmd) == 0)
	return (0);
    }
  else
    if (rd_and_exe(sys, last_cmd) == 0)
      return (0);
  if (sys->cmd != NULL)
    sys->cmd = sys->cmd->next;
  return (1);
}

int	controle(t_system *sys)
{
  t_cmd	*tmp;
  int	last_cmd;

  last_cmd = 0;
  tmp = sys->cmd;
  sys->lcmd_fail = false;
  if (sys->cmd == NULL || sys->cmd->cmd == NULL)
    return (1);
  set_pipe(sys);
  while (sys->cmd != NULL)
    {
      if (ctrl_param(sys, &last_cmd) == 0)
	{
	  sys->cmd = tmp;
	  return (0 * printf("error in command line\n"));
	}
      else if (sys->exit.exit == true)
	{
	  sys->cmd = tmp;
	  return (1);
	}
    }
  clean_fd(sys);
  sys->cmd = tmp;
  return (1);
}
