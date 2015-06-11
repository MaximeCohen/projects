/*
** replace_line.c for replace_line in /home/huet_f/rendu/PSU/PSU_2014_42sh/src
**
** Made by Florian Huet
** Login   <huet_f@epitech.net>
**
** Started on  Fri May 22 15:10:16 2015 Florian Huet
** Last update Sun May 24 23:13:07 2015 enzo resse
*/

#include "42sh.h"

char	*begin_of_line(char *line, int	i)
{
  char	*new_line;
  int	x;

  x = 0;
  if ((new_line = malloc(sizeof(char) * (my_strlen(line)) + 1)) == NULL)
    {
      write(2, "Malloc error\n", my_strlen("Malloc error\n"));
      return (NULL);
    }
  while (x < i)
    {
      new_line[x] = line[x];
      ++x;
    }
  new_line[x] = '\0';
  return (new_line);
}

char	*short_line(char *new_line, char *line, char *new_elem, int i)
{
  char	*beg;

  beg = begin_of_line(line, i);
  sprintf(new_line, "%s%s",
	  beg,
	  new_elem);
  free(beg);
  free(line);
  return (new_line);
}

void	free_bl(char *line, char *beg)
{
  free(beg);
  free(line);
}

char	*replace_line(char *line, char *elem, char *new_elem, int n)
{
  char	*new_line;
  char	*beg;
  int	i;

  i = n - 1;
  if ((new_line = calloc(sizeof(char) * (my_strlen(line) + my_strlen(new_elem))
			 , (my_strlen(line) + my_strlen(new_elem)))) == NULL)
    return (NULL);
  while (line[++i])
    if (!(strncmp(&line[i], elem, my_strlen(elem))))
      {
	if (line[i + my_strlen(elem)] == '\0')
	  return (new_line = short_line(new_line, line, new_elem, i));
	else
	  {
	    if ((beg = begin_of_line(line, i)) == NULL)
	      return (NULL);
	    sprintf(new_line, "%s%s%s", beg, new_elem,
		    &line[my_strlen(beg) + my_strlen(elem)]);
	    free_bl(line, beg);
	    return (new_line);
	  }
      }
  free(new_line);
  return (NULL);
}
