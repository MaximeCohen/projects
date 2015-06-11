/*
** my_getenv.c for  in /home/agor_m/RenduTek1/minishell
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Fri Jan 23 13:55:41 2015 Maxime Agor
** Last update Tue May 19 16:25:32 2015 enzo resse
*/

#include "42sh.h"

char	*my_getenv(char **env, char *var)
{
  int	i;
  char	*str;
  int	len;

  i = 0;
  str = my_strdog(var, "=");
  if (!str)
    {
      printf("An error occured\n");
      return (0);
    }
  len = my_strlen(str);
  while (env && env[i])
    {
      if (strncmp(str, env[i], len) == 0)
	{
	  free(str);
	  return (&(env[i][len]));
	}
      ++i;
    }
  free(str);
  return (0);
}
