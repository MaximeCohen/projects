/*
** ctrl_param.c for 42sh in /home/resse_e/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Thu May 21 10:35:55 2015 enzo resse
** Last update Fri May 22 22:38:24 2015 enzo resse
*/

#include "42sh.h"

int	simple_rd(t_system *sys, int *last_cmd)
{
  if (*last_cmd == 1)
    return (0);
  if (init_spr(sys) == 0)
    {
      reset_pipe(sys);
      sys->lcmd_fail = true;
    }
  else
    sys->lcmd_fail = false;
  *last_cmd = 1;
  return (1);
}

int	rd_and_exe(t_system *sys, int *last_cmd)
{
  int	ctrl_spr;

  if (sys->cmd->next != NULL && sys->cmd->next->separator == PIPE)
    *last_cmd = 1;
  else
    *last_cmd = 0;
  if ((ctrl_spr = ctrl_rd(sys)) == 0)
    return (0);
  if (sys->lcmd_fail == false)
    {
      if (ctrl_exe(sys) == 0)
	{
	  reset_pipe(sys);
	  sys->lcmd_fail = true;
	}
      else
	sys->lcmd_fail = false;
    }
  if (sys->cmd != NULL && ctrl_spr == 2)
    sys->cmd = sys->cmd->next;
  return (1);
}
