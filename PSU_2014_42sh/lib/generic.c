/*
** generic.c for generic in /home/huet_f/rendu/PSU/PSU_2014_42sh
**
** Made by Florian Huet
** Login   <huet_f@epitech.net>
**
** Started on  Fri May  8 12:24:33 2015 Florian Huet
** Last update Wed May 20 18:56:04 2015 leo lzfon
*/

#include <42sh.h>

void	aff_path(t_system *sys)
{
  int	i;

  i = 0;
  while (sys->path && sys->path[i])
    {
      write(1, sys->path[i], my_strlen(sys->path[i]));
      write(1, "\n", 1);
      ++i;
    }
}

void	aff_env(t_system *sys)
{
  int	i;

  i = 0;
  while (sys->env && sys->env[i])
    {
      write(1, sys->env[i], my_strlen(sys->env[i]));
      write(1, "\n", 1);
      ++i;
    }
}

void	put_error(char *error)
{
  write(2, error, my_strlen(error));
  write(2, "\n", 1);
  exit(EXIT_FAILURE);
}
