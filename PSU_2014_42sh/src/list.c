/*
** list.c for list 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Thu May  7 11:59:27 2015 leo lzfon
** Last update Sun May 24 22:00:56 2015 leo lzfon
*/

#include "42sh.h"

t_cmd	*put_in_cmd_list(char **data, t_cmd *list, char sep_type)
{
  t_cmd	*new_elem;
  t_cmd	*tmp;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    put_error(MALLOC);
  new_elem->cmd = data;
  new_elem->separator = sep_type;
  new_elem->next = NULL;
  new_elem->prev = NULL;
  if (list == NULL)
    list = new_elem;
  else
    {
      tmp = list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_elem;
      new_elem->prev = tmp;
    }
  return (list);
}

void	delete_link(t_cmd **link)
{
  int	i;
  t_cmd	*tmp;

  i = 0;
  tmp = *link;
  *link = (*link)->next;
  tmp->prev->next = *link;
  if (*link != NULL)
    (*link)->prev = tmp->prev;
  while (tmp->cmd && tmp->cmd[i])
    {
      free(tmp->cmd[i]);
      ++i;
    }
  free(tmp->cmd);
  free(tmp);
}
