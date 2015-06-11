/*
** unalias.c for 42sh in /home/cohen_h/Bureau/rendu/B2/B2-Systeme_Unix/PSU_2014_42sh/bonus
**
** Made by cohen_h
** Login   <cohen_h@epitech.net>
**
** Started on  Fri May 22 13:53:17 2015 cohen_h
** Last update Sun May 24 21:39:56 2015 Maxime Agor
*/

#include "42sh.h"

void		dell_alias(char *str, t_alias **alias, int curs)
{
  t_alias	*tmp;

  tmp = *alias;
  while (tmp)
    {
      if (curs == 1 && strcmp(str, "-a") == 0)
	{
	  dell_alias_tolist(alias, tmp->name);
	  tmp = *alias;
	}
      else if (strcmp(str, tmp->name) == 0)
	{
	  dell_alias_tolist(alias, tmp->name);
	  tmp = *alias;
	}
      else
	tmp = tmp->next;
    }
}

int	my_unalias(t_system *sys)
{
  int	i;

  if (wordtab_len(sys->cmd->cmd) == 1)
    {
      fprintf(stderr, "unalias: Too few arguments.\n");
      return (1);
    }
  i = 1;
  while (sys->cmd->cmd[i])
    {
      dell_alias(sys->cmd->cmd[i], &sys->alias, i);
      ++i;
    }
  return (1);
}
