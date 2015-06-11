/*
** operateur.c for 42sh in /home/resse_e/PSU_2014_42sh/src/pipe
**
** Made by enzo resse
** Login   <resse_e@epitech.net>
**
** Started on  Fri May 15 10:37:05 2015 enzo resse
** Last update Sat May 23 13:45:41 2015 Maxime Agor
*/

#include "42sh.h"

int	and(t_system *sys)
{
  if (sys->lcmd_fail == false)
    {
      sys->lcmd_fail = false;
      return (1);
    }
  else
    operator_delete(sys);
  return (1);
}

int	or(t_system *sys)
{
  if (sys->lcmd_fail == true)
    {
      sys->lcmd_fail = false;
      return (1);
    }
  else
    operator_delete(sys);
  return (1);
}

void	operator_delete(t_system *sys)
{
  while (sys->cmd != NULL && (sys->cmd->separator != 0 ||
			      sys->cmd->separator != 6 ||
			      sys->cmd->separator != 7))
    {
      delete_link(&(sys->cmd));
    }
}
