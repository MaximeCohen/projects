/*
** history.c for history in /home/huet_f/rendu/PSU/PSU_2014_42sh
**
** Made by Florian Huet
** Login   <huet_f@epitech.net>
**
** Started on  Thu May 14 10:59:17 2015 Florian Huet
** Last update Thu May 21 23:33:51 2015 leo lzfon
*/

#include "42sh.h"

void		aff_history(t_hist *history)
{
  t_hist	*tmp;

  tmp = history;
  while (tmp != NULL)
    {
      printf("\n\nline = %s\nid = %d\n\n", tmp->line, tmp->id);
      tmp = tmp->next;
    }
}

void		delete_last(t_hist *history)
{
  t_hist	*tmp;

  tmp = history->next;
  if (!tmp)
    return ;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->prev->next = NULL;
  free(tmp);
}

void		add_elem(t_hist *root, char *line, int i)
{
  t_hist	*new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    put_error(MALLOC);
  if ((new_elem->line = malloc(sizeof(char) * my_strlen(line) + 1)) == NULL)
    put_error(MALLOC);
  new_elem->line = !line ? NULL : strcpy(new_elem->line, line);
  new_elem->id = i;
  new_elem->next = root->next;
  new_elem->prev = root;
  if (root->next)
    root->next->prev = new_elem;
  root->next = new_elem;
}

void		save_line(t_system *sys, char *line)
{
  static int	i = 0;

  ++i;
  if (i > 100)
    delete_last(sys->history);
  add_elem(sys->history, line, i);
}

void	reset_history(t_system *sys)
{
  while (sys->history->id != -1)
    sys->history = sys->history->prev;
}
