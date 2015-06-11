/*
** arrow.c for 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Wed May 20 11:59:05 2015 leo lzfon
** Last update Sun May 24 22:09:18 2015 Maxime Agor
*/

#include "42sh.h"

void	clean_line(char *line)
{
  int	i;
  char	*prompt;

  i = 0;
  prompt = my_getenv(get_sys(NULL)->env, "PROMPT");
  while (i < my_strlen(line) + (prompt ? my_strlen(prompt) + 3 : 6))
    {
      my_putstr("\b \b");
      ++i;
    }
  aff_prompt(get_sys(NULL));
}

char	is_arrow(char *buffer)
{
  if (buffer[0] == 27 && buffer[1] == 91)
    {
      if (buffer[2] == 67 || buffer[2] == 68 ||
	  buffer[2] == 66 || buffer[2] == 65)
	return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

char	*up_history(t_system *sys, char *line)
{
  if (!sys->history->next || !sys->history->next->line)
    return (line);
  else
    {
      clean_line(line);
      my_putstr(sys->history->next->line);
      sys->history = sys->history->next;
    }
  return (sys->history->line ? strdup(sys->history->line) : NULL);
}

char	*down_history(t_system *sys, char *line)
{
  clean_line(line);
  if (!sys->history->prev)
    return (NULL);
  else
    {
      my_putstr(sys->history->prev->line);
      sys->history = sys->history->prev;
    }
  return (sys->history->line ? strdup(sys->history->line) : NULL);
}

char	*manage_arrow(t_system *sys, char *line, char *buffer)
{
  if (buffer && buffer[2] == 65)
    return (up_history(sys, line));
  else if (buffer && buffer[2] == 66)
    return (down_history(sys, line));
  else
    return (line);
}
