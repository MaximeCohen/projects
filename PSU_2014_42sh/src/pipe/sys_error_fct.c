/*
** sys_error_fct.c for 42sh in /home/resse_e/rendu/PSU_2014_42sh/src/pipe
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Sat May  9 11:29:17 2015 enzo resse
** Last update Fri May 22 22:43:14 2015 enzo resse
*/

#include "42sh.h"

int	fail(void)
{
  printf("[ERROR] 0 :system error\n");
  return (0);
}

int	nothing(void)
{
  return (1);
}

int	bad_fd(void)
{
  return (1);
}

int	fd_stoped(void)
{
  printf("[ERROR] 2 :fd stoped by signal\n");
  return (0);
}

int	fd_limited(void)
{
  printf("[ERROR] 3 :to many fd are in use for the process or the system\n");
  return (0);
}
