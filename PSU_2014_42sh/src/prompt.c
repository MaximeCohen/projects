/*
** prompt.c for 42sh in /home/resse_e/PSU_2014_42sh/src
** 
** Made by enzo resse
** Login   <resse_e@epitech.net>
** 
** Started on  Sun May 24 18:06:56 2015 enzo resse
** Last update Sun May 24 20:04:28 2015 enzo resse
*/

#include "42sh.h"

t_system		*get_sys(t_system *sys)
{
  static t_system	*system = NULL;

  if (sys != NULL)
    system = sys;
  return (system);
}

int	aff_prompt(t_system *sys)
{
  char	*str;

  if (sys->exit.exit == true)
    return (0);
  str = my_getenv(sys->env, "PROMPT");
  if (str == NULL)
    my_putstr("><> : ");
  else
    {
      str = replace_cmd(sys, strdup(str), LOOP_TURN, 0);
      my_putstr(str);
      my_putstr(" : ");
      free(str);
    }
  return (0);
}
