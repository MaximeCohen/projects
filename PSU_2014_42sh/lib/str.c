/*
** str.c for str 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Wed May  6 20:57:13 2015 leo lzfon
** Last update Thu May 21 19:52:47 2015 leo lzfon
*/

#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	len;

  len = 0;
  while (str && str[len])
    ++len;
  return (len);
}

void	my_putstr(char *str)
{
  if (str)
    write(1, str, my_strlen(str));
}

char	*my_str_concat(char *s1, char *s2, char delimiter)
{
  char	*concat;
  int	i;
  int	j;

  if ((concat = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2)))
      == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (s1 && s1[i])
    concat[j++] = s1[i++];
  i = 0;
  if (delimiter > 0)
    concat[j++] = delimiter;
  while (s2 && s2[i])
    {
      concat[j] = s2[i];
      ++i;
      ++j;
    }
  concat[j] = '\0';
  return (concat);
}
