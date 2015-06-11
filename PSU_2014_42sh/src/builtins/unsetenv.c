/*
** unsetenv.c for  in /home/agor_m/RenduTek1/minishell
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Sun Feb  1 17:49:03 2015 Maxime Agor
** Last update Sun May 24 21:40:42 2015 Maxime Agor
*/

#include "42sh.h"

int	builtin_unsetvar(char ***env, int i)
{
  int	do_while;

  do_while = 1;
  free((*env)[i]);
  while ((*env)[i] || do_while)
    {
      do_while = 0;
      (*env)[i] = (*env)[i + 1];
      ++i;
    }
  if ((*env)[i] == NULL)
    {
      if (!(*env = realloc(*env, sizeof(char *) * i)))
	return (0);
      (*env)[i - 1] = 0;
    }
  return (1);
}

int	my_unsetenv(t_system *sys)
{
  int	i;
  int	tmp;

  i = 0;
  if (wordtab_len(sys->cmd->cmd) != 2)
    return (1 + 0 * printf("usage : %s [VAR].\n", sys->cmd->cmd[0]));
  while (sys->env[i])
    {
      if (sys->env[i] + my_strlen(sys->cmd->cmd[1]) + 1 ==
	  my_getenv(sys->env, sys->cmd->cmd[1]))
	{
	  tmp = builtin_unsetvar(&(sys->env), i);
	  return (tmp);
	}
      ++i;
    }
  printf("Environment variable %s not found\n", sys->cmd->cmd[1]);
  return (1);
}
