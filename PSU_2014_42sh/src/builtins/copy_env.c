/*
** copy_env.c for  in /home/agor_m/RenduTek1/minishell
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Fri Jan 23 11:43:56 2015 Maxime Agor
** Last update Sat May 23 15:05:18 2015 Maxime Agor
*/

#include "42sh.h"

void	print_wordtab(char **wordtab)
{
  int	i;

  i = 0;
  while (wordtab && wordtab[i])
    printf("%s\n", wordtab[i++]);
}

int	get_wordtab_len(char **wordtab)
{
  int	i;

  if (!wordtab)
    return (0);
  i = 0;
  while (wordtab[i])
    ++i;
  return (i);
}

char	**copy_env(char **env)
{
  char	**env_cpy;
  int	i;
  int	len;

  len = get_wordtab_len(env);
  if (!(env_cpy = malloc(sizeof(char *) * (len + 1))))
    return (0);
  i = 0;
  while (i < len)
    {
      env_cpy[i] = strdup(env[i]);
      ++i;
    }
  env_cpy[i] = 0;
  return (env_cpy);
}
