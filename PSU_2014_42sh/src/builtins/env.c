/*
** env.c for  in /home/agor_m/RenduTek1/minishell
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Sun Feb  1 17:49:03 2015 Maxime Agor
** Last update Sun May 24 20:35:50 2015 Maxime Agor
*/

#include "42sh.h"

int	my_env(t_system *sys)
{
  int	i;

  i = 0;
  if (!sys->env)
    return (-1);
  while (sys->env[i])
    {
      my_putstr(sys->env[i]);
      my_putstr("\n");
      ++i;
    }
  return (1);
}
