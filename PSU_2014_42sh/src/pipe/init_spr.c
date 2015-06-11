/*
** init_spr.c for 42sh in /home/resse_e/rendu/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Fri May  8 11:01:54 2015 enzo resse
** Last update Fri May 22 22:40:24 2015 enzo resse
*/

#include "42sh.h"

int		init_spr(t_system *sys)
{
  static int	(*spr[])(t_system *sys) =
    {
      &reset_pipe,
      &init_pipe,
      &rd_right,
      &drd_right,
      &rd_left,
      &drd_left,
      &and,
      &or,
      &reset_pipe,
      NULL
    };

  return (spr[sys->cmd->separator](sys));
}
