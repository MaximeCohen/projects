/*
** alias_list.c for 42sh in /home/cohen_h/Bureau/rendu/B2/B2-Systeme_Unix/PSU_2014_42sh/bonus
** 
** Made by cohen_h
** Login   <cohen_h@epitech.net>
** 
** Started on  Tue May 19 14:45:11 2015 cohen_h
** Last update Sun May 24 19:19:12 2015 cohen_h
*/

#include "42sh.h"

int		add_alias_tolist(t_alias **alias, char *name, char *value)
{
  t_alias	*tmp;
  t_alias	*newalias;

  tmp = *alias;
  while (tmp && tmp->next && strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  if (tmp && strcmp(tmp->name, name) == 0)
    {
      free(name);
      free(tmp->value);
      tmp->value = value;
      return (EXIT_SUCCESS);
    }
  if (!(newalias = malloc(sizeof(*newalias))))
    return (EXIT_FAILURE);
  newalias->name = name;
  newalias->value = value;
  newalias->next = NULL;
  if (*alias == NULL)
    *alias = newalias;
  else
    tmp->next = newalias;
  return (EXIT_SUCCESS);
}

void	free_select_alias(t_alias *alias)
{
  free(alias->name);
  free(alias->value);
  free(alias);
}

int		dell_alias_tolist(t_alias **alias, char *name)
{
  t_alias	*tmp;
  t_alias	*oldtmp;

  tmp = *alias;
  while (tmp && tmp->next && strcmp(tmp->name, name) != 0)
    {
      oldtmp = tmp;
      tmp = tmp->next;
    }
  if (tmp == *alias && strcmp(tmp->name, name) == 0)
    {
      *alias = tmp->next;
      free_select_alias(tmp);
    }
  else if (strcmp(tmp->name, name) == 0)
    {
      oldtmp->next = tmp->next;
      free_select_alias(tmp);
    }
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
