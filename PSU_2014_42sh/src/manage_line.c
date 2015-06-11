/*
** manage_line.c for 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Wed May 20 17:53:23 2015 leo lzfon
** Last update Sun May 24 22:46:00 2015 leo lzfon
*/

#include "42sh.h"

int	my_strlen(char *);

char	*append_to_line(char *buffer, char *line)
{
  int	i;
  int	j;
  char	*new_line;

  if (!line)
    return (strdup(buffer));
  if (!(new_line = malloc(sizeof(char) *
			  (my_strlen(line) + my_strlen(buffer) + 1))))
    return (NULL);
  i = 0;
  j = 0;
  while (line[i])
    {
      new_line[i] = line[i];
      ++i;
    }
  while (buffer[j])
    {
      new_line[i] = buffer[j];
      ++i;
      ++j;
    }
  new_line[i] = 0;
  free(line);
  return (new_line);
}

char	*decrease_line(t_system *sys, char *line)
{
  int	i;
  char	*new_line;

  (void)sys;
  if (!line)
    return (NULL);
  else if (my_strlen(line) == 1)
    {
      write(1, "\b \b", 3);
      free(line);
      return (NULL);
    }
  if (!(new_line = malloc(sizeof(char) * my_strlen(line))))
    return (NULL);
  i = 0;
  while (i < my_strlen(line) - 1)
    {
      new_line[i] = line[i];
      ++i;
    }
  new_line[i] = 0;
  write(1, "\b \b", 3);
  free(line);
  return (new_line);
}
