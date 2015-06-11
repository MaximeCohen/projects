/*
** set_pwd.c for  in /home/agor_m/RenduTek1/minishell2
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Wed Mar  4 23:36:42 2015 Maxime Agor
** Last update Tue May 19 16:39:19 2015 enzo resse
*/

#include "42sh.h"

char	*set_pwd_loop(char **command, char *pwd, int pos)
{
  char	*tmp;
  int	i;

  while (command[pos])
    {
      if (strcmp(command[pos], "..") == 0)
	{
	  i = strlen(pwd) - 2;
	  if (i >= 0)
	    pwd[i] = '\0';
	  while ((i >= 0) && pwd[i] != '/')
	    pwd[i--] = '\0';
	}
      else if (strcmp(command[pos], ".") != 0)
	{
	  tmp = pwd;
	  pwd = my_strdog(tmp, command[pos]);
	  free(tmp);
	  tmp = pwd;
	  pwd = my_strdog(tmp, "/");
	  free(tmp);
	}
      ++pos;
    }
  return (pwd);
}

int	set_pwd(char ***env, char *path)
{
  char	*final_pwd;
  char	**command;
  int	i;

  i = (strncmp(path, "~/", 2) == 0) ? 1 : 0;
  if (i == 1 || (strncmp(path, "~\0", 2) == 0))
    {
      if (!(final_pwd = my_strdog(my_getenv(*env, "HOME"), "/")))
	return (1);
    }
  else if (path[0] == '/')
    {
      if (!(final_pwd = strdup("/")))
	return (-1);
    }
  else
    if (!(final_pwd = my_strdog(my_getenv(*env, "PWD"), "/")))
      return (1);
  if (!(command = my_str_to_wordtab2(path, "/")))
    return (1);
  final_pwd = set_pwd_loop(command, final_pwd, i);
  builtin_setenv(env, "PWD", final_pwd);
  free(final_pwd);
  return (1);
}
