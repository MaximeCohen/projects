/*
** free.c for free 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Sat May  9 20:54:46 2015 leo lzfon
** Last update Sun May 24 21:52:57 2015 leo lzfon
*/

#include "42sh.h"

void	free_dollar(char *s1, char *s2, char *s3)
{
  free(s1);
  free(s2);
  free(s3);
}

void	free_cmd(t_cmd *cmd)
{
  t_cmd	*tmp;
  t_cmd	*next_cmd;
  int	i;

  i = 0;
  tmp = cmd;
  while (tmp != NULL)
    {
      if (tmp->cmd != NULL)
	{
	  while (tmp->cmd[i] != NULL)
	    {
	      free(tmp->cmd[i]);
	      ++i;
	    }
	  i = 0;
	  free(tmp->cmd);
	}
      next_cmd = tmp->next;
      free(tmp);
      tmp = next_cmd;
    }
}

void		free_history(t_hist *hist)
{
  t_hist	*tmp;
  t_hist	*next_hist;

  tmp = hist;
  while (tmp != NULL)
    {
      free(tmp->line);
      next_hist = tmp->next;
      free(tmp);
      tmp = next_hist;
    }
}

void		free_alias(t_alias *alias)
{
  t_alias	*tmp;
  t_alias	*next_alias;

  tmp = alias;
  while (tmp != NULL)
    {
      next_alias = tmp->next;
      free_select_alias(tmp);
      tmp = next_alias;
    }
}

void	free_all(t_system *sys)
{
  free_wordtab(sys->env);
  free_wordtab(sys->path);
  free_history(sys->history);
  free_alias(sys->alias);
}
