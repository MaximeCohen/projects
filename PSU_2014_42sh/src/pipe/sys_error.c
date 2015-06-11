/*
** sys_error.c for 42sh in /home/resse_e/rendu/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Sat May  9 11:23:52 2015 enzo resse
** Last update Sun May 10 17:50:42 2015 enzo resse
*/

#include "42sh.h"

int		sys_error(int error_type)
{
  static int	(*error[])(void) =
    {
      &fail,
      &nothing,
      &bad_fd,
      &fd_stoped,
      &fd_limited,
      NULL
    };

  return (error[error_type]());
}
