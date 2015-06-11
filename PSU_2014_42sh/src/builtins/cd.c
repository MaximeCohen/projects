/*
** cd.c for  in /home/agor_m/RenduTek1/minishell
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Sun Feb  1 17:49:03 2015 Maxime Agor
** Last update Tue May 19 21:18:32 2015 Maxime Agor
*/

#include "42sh.h"

int	builtin_cdhome(char ***env)
{
  char	*home;
  char	*pwd;

  if (!env)
    return (1 + 0 * printf("environment not found\n"));
  if (!(home = my_getenv(*env, "HOME")))
    return (1 + 0 * printf("HOME not found\n"));
  if (!(pwd = my_getenv(*env, "PWD")))
    return (1 + 0 * printf("PWD not found\n"));
  if (chdir(home) < 0)
    return (1 + 0 * printf("error : cannot go to the home\n"));
 if (builtin_setenv(env, "OLDPWD", pwd) < 0)
    return (-1);
  return (builtin_setenv(env, "PWD", home));
}

int	builtin_backcd(char ***env)
{
  char	*pwd;
  char	*oldpwd;

  if (!env)
    return (1 + 0 * printf("environment not found\n"));
  if (!(pwd = my_getenv(*env, "PWD")))
    return (1 + 0 * printf("PWD not found\n"));
  if (!(oldpwd = strdup(my_getenv(*env, "OLDPWD"))))
    return (1 + 0 * printf("OLDPWD not found\n"));
  if (chdir(oldpwd) < 0)
    return (1 + 0 * printf("error : cannot go to the oldpwd\n"));
  if (builtin_setenv(env, "OLDPWD", pwd) < 0)
      return (-1);
  if (builtin_setenv(env, "PWD", oldpwd) < 0)
    return (-1);
  free(oldpwd);
  return (1);

}

int	my_cd(t_system *sys)
{
  char	*pwd;
  int	ac;

  ac = wordtab_len(sys->cmd->cmd);
  if (ac > 2)
    return (1 + 0 * printf("usage : %s [PATH]\n", sys->cmd->cmd[0]));
  if (ac == 1)
    return (builtin_cdhome(&(sys->env)));
  else if (strcmp(sys->cmd->cmd[1], "-") == 0)
    return (builtin_backcd(&(sys->env)));
  else
    {
      if (chdir(sys->cmd->cmd[1]) < 0)
	return (1 + 0 * printf("folder not found : %s\n", sys->cmd->cmd[1]));
      if (!(pwd = my_getenv(sys->env, "PWD")))
	return (1 + 0 * printf("PWD not found\n"));
      if (builtin_setenv(&(sys->env), "OLDPWD", pwd) < 0)
	return (-1);
      return (set_pwd(&(sys->env), sys->cmd->cmd[1]));
    }
  return (1);
}
