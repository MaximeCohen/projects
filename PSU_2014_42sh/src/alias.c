/*
** alias.c for 42sh in /home/cohen_h/Bureau/rendu/B2/B2-Systeme_Unix/PSU_2014_42sh/bonus
**
** Made by cohen_h
** Login   <cohen_h@epitech.net>
**
** Started on  Tue May 19 14:36:05 2015 cohen_h
** Last update Sun May 24 21:40:14 2015 Maxime Agor
*/

#include "42sh.h"

int		aff_alias(t_alias **alias, char *name)
{
  t_alias	*tmp;

  tmp = *alias;
  while (tmp)
    {
      if (name == NULL || strcmp(name, tmp->name) == 0)
      	printf("%s\t%s\n", tmp->name, tmp->value);
      tmp = tmp->next;
    }
  return (1);
}

int	add_alias(t_system *sys)
{
  int	i;
  char	*name;
  char	*value;
  char	*tmp;

  if (!(name = malloc((strlen(sys->cmd->cmd[1]) + 1) * sizeof(char))) ||
      !(value = malloc((strlen(sys->cmd->cmd[2]) + 1) * sizeof(char))))
    return (0);
  strcpy(name, sys->cmd->cmd[1]);
  strcpy(value, sys->cmd->cmd[2]);
  i = 3;
  while (sys->cmd->cmd[i])
    {
      tmp = value;
      if (!(value = my_strdog(tmp, " ")))
	return (0);
      free(tmp);
      tmp = value;
      if  (!(value = my_strdog(tmp, sys->cmd->cmd[i])))
	return (0);
      ++i;
      free(tmp);
    }
  return (add_alias_tolist(&sys->alias, name, value));
}

int	my_alias(t_system *sys)
{
  int	status;

  status = 0;
  if (wordtab_len(sys->cmd->cmd) == 1)
    status = aff_alias(&sys->alias, NULL);
  else if (wordtab_len(sys->cmd->cmd) == 2)
    status = aff_alias(&sys->alias, sys->cmd->cmd[1]);
  else
    status = add_alias(sys);
  return (status);
}
