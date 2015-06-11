/*
** get_next_line.c for get_next_line in /home/cohen_h/Bureau/rendu/B1-C-Prog_Elem/CPE_2014_get_next_line
**
** Made by cohen_h
** Login   <cohen_h@epitech.net>
**
** Started on  Mon Dec 15 15:31:55 2014 cohen_h
** Last update Wed May 20 22:26:28 2015 Florian Huet
*/

#include <stdlib.h>
#include <unistd.h>

char	*get_line(char *dest, char *src, int ind, int *start)
{
  char	*tmp;
  int	i;
  int	j;

  i = -1;
  j = 0;
  if (dest)
    while (dest[j])
      ++j;
  if (!(tmp = malloc(j + ind + 1)))
    return (NULL);
  while (++i < j)
    tmp[i] = dest[i];
  j = 0;
  while (j < ind)
    {
      tmp[i + j] = src[*start + j];
      ++j;
    }
  tmp[i + j] = '\0';
  if (dest)
    free(dest);
  *start += ind + 1;
  return (tmp);
}

char		*get_next_line(const int fd)
{
  static char	buff[1000 + 1];
  static int	size;
  static int	start;
  int		ind;
  char		*line;

  line = NULL;
  ind = 0;
  while (1)
    {
      if (start >= size)
        {
	  start = 0;
	  size = read(fd, buff, 1000);
	  if (size <= 0)
	    return (line);
	  ind = 0;
        }
      if (buff[start + ind] == '\n')
	return (get_line(line, buff, ind, &start));
      if (start + ind == size - 1)
	line = get_line(line, buff, ind + 1, &start);
      ++ind;
    }
}
