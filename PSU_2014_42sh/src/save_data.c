/*
** save_data.c for save_date in /home/huet_f/rendu/PSU/PSU_2014_42sh
**
** Made by Florian Huet
** Login   <huet_f@epitech.net>
**
** Started on  Fri May  8 12:12:24 2015 Florian Huet
** Last update Sat May  9 20:35:07 2015 leo lzfon
*/

#include "42sh.h"

char	save_env_and_path(t_system *sys, char **env)
{
  int	i;

  i = 0;
  if (env == NULL)
    return (EXIT_FAILURE);
  while (env && env[i])
    {
      if (strncmp(env[i], "PATH=", 5) == 0)
	sys->path = my_str_to_wordtab(&env[i][5], 0, 0);
      ++i;
    }
  if ((sys->env = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (EXIT_FAILURE);
  i = 0;
  while (env[i])
    {
      if ((sys->env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1)))
	  == NULL)
	return (EXIT_FAILURE);
      sys->env[i] = strcpy(sys->env[i], env[i]);
      ++i;
    }
  sys->env[i] = NULL;
  return (EXIT_SUCCESS);
}
