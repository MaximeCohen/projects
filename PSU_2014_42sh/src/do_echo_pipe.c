/*
** do_echo_pipe.c for 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Sat May 23 19:27:44 2015 leo lzfon
** Last update Sun May 24 21:30:38 2015 leo lzfon
*/

#include "42sh.h"

char	*concat_line_buffer(char *line, char *buffer)
{
  char	*new_line;
  int	i;
  int	j;

  if (!(new_line = malloc(sizeof(char) *
			  (my_strlen(line) + my_strlen(buffer)))))
    return (NULL);
  i = 0;
  j = 0;
  while (line && line[i])
    {
      new_line[i] = line[i];
      ++i;
    }
  while (buffer && buffer[j] && buffer[j] != '\n')
    {
      new_line[i] = buffer[j];
      ++i;
      ++j;
    }
  new_line[i] = 0;
  free(line);
  return (new_line);
}

char	*concat_buffer(char *buffer)
{
  char	*new_line;
  int	i;

  if (!(new_line = malloc(sizeof(char) * my_strlen(buffer) + 1)))
    return (NULL);
  i = 0;
  while (buffer && buffer[i] && buffer[i] != '\n')
    {
      new_line[i] = buffer[i];
      ++i;
    }
  new_line[i] = 0;
  return (new_line);
}

char	*do_echo_pipe(t_system *sys, char *line, char *buffer)
{
  char	*new_line;

  new_line = !line ? concat_buffer(buffer) : concat_line_buffer(line, buffer);
  send_line(sys, &new_line);
  sys->exit.exit = true;
  return (NULL);
}
