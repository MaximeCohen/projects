/*
** setenv.c for  in /home/agor_m/RenduTek1/minishell
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Sun Feb  1 17:49:03 2015 Maxime Agor
** Last update Sun May 24 21:39:02 2015 Maxime Agor
*/

#include "42sh.h"

int	builtin_setvar(char ***env, int pos, char *var, char *value)
{
  char	*newvar;
  char	*tmp;

  if (!(tmp = my_strdog(var, "=")))
    return (-1);
  if (!(newvar = my_strdog(tmp, value)))
    return (-1);
  free(tmp);
  if ((*env)[pos])
    free((*env)[pos]);
  (*env)[pos] = newvar;
  return (1);
}

int	builtin_createvar(char ***env, int pos, char *var, char *value)
{
  char	*newvar;
  char	*tmp;

  if (!((*env) = realloc(*env, sizeof(char *) * (pos + 2))))
    return (-1);
  if (!(tmp = my_strdog(var, "=")))
    return (-1);
  if (!(newvar = my_strdog(tmp, value)))
    return (-1);
  free(tmp);
  (*env)[pos] = newvar;
  (*env)[pos + 1] = NULL;
  return (1);
}

int	builtin_setenv(char ***env, char *var, char *value)
{
  int	i;

  i = 0;
  while ((*env)[i])
    {
      if ((*env)[i] + my_strlen(var) + 1 == my_getenv((*env), var))
	{
	  return (builtin_setvar(env, i, var, value));
	}
      ++i;
    }
  return (builtin_createvar(env, i, var, value));
}

int	my_setenv(t_system *sys)
{
  int	tmp;
  char	*path;
  int	ac;

  ac = wordtab_len(sys->cmd->cmd);
  if (ac == 1)
    return (my_env(sys));
  tmp = builtin_setenv(&(sys->env),
		       sys->cmd->cmd[1], ac > 2 ? sys->cmd->cmd[2] : "");
  path = my_getenv(sys->env, "PATH");
  if (path)
    sys->path = my_str_to_wordtab(path, 0, 0);
  return (tmp);
}
