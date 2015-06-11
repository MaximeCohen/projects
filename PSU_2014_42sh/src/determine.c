/*
** determine.c for determine 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Sun May 10 10:19:44 2015 leo lzfon
** Last update Sun May 24 22:57:39 2015 Florian Huet
*/

#include "42sh.h"

char	determine_builtin(t_cmd *cmd)
{
  char	*builtin_tab[8];
  int	i;

  if (!cmd->cmd || !cmd->cmd[0])
    return (EXIT_FAILURE);
  i = 0;
  builtin_tab[0] = "exit";
  builtin_tab[1] = "cd";
  builtin_tab[2] = "echo";
  builtin_tab[3] = "env";
  builtin_tab[4] = "setenv";
  builtin_tab[5] = "unsetenv";
  builtin_tab[6] = "alias";
  builtin_tab[7] = "unalias";
  while (i < 8)
    {
      if (!strcmp(cmd->cmd[0], builtin_tab[i]))
	{
	  cmd->builtin = i;
	  return (EXIT_SUCCESS);
	}
      ++i;
    }
  cmd->builtin = NONE;
  return (EXIT_FAILURE);
}

char	determine_exec(t_cmd *cmd, char **path)
{
  int	i;
  char	*concat;

  i = 0;
  if (!cmd->cmd || !cmd->cmd[0])
    return (EXIT_FAILURE);
  if (!strncmp(cmd->cmd[0], "./", 2) || !strncmp(cmd->cmd[0], "/", 1))
    {
      if (!access(cmd->cmd[0], X_OK))
	return (EXIT_SUCCESS);
      return (EXIT_FAILURE);
    }
  while (path && path[i])
    {
      concat = my_str_concat(path[i], cmd->cmd[0], '/');
      if (!access(concat, X_OK))
	{
	  cmd->cmd[0] = concat;
	  return (EXIT_SUCCESS);
	}
      ++i;
    }
  return (EXIT_FAILURE);
}

char	determine_cmd(t_system *sys)
{
  t_cmd	*tmp;

  tmp = sys->cmd;
  while (tmp)
    {
      if (tmp->cmd && tmp->cmd[0])
	{
	  if (!determine_builtin(tmp))
	    tmp->file = false;
	  else if (!determine_exec(tmp, sys->path))
	    {
	      tmp->file = false;
	    }
	  else
	    tmp->file = true;
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
