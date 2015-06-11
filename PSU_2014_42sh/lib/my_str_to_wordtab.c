/*
** my_str_to_wordtab.c for my_str_to_wordtab* in /home/lafon_l/rendu/Piscine_C_J08/ex_04
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Fri Oct 24 10:35:04 2014 leo lzfon
** Last update Sat May 23 15:53:43 2015 leo lzfon
*/

#include "42sh.h"

int	is_alnum(char k)
{
  if ((k >= 'A' && k <= 'Z') || (k >= 'a' && k <= 'z')
      || (k >= '0' && k <= '9') || (k == '/') || (k == '.')
      || (k == '-') || (k == '=') || (k == '|') || (k == '>'))
    return (1);
  return (0);
}

int	count_words(char *str)
{
  int	i;
  int	word;

  i = 0;
  word = 0;
  while (str[i] != '\0')
    {
      if (is_alnum(str[i]))
	{
	  word = word + 1;
	  while (str[i] != '\0' && is_alnum(str[i]))
	    i = i + 1;
	  if (str[i] == '\0')
	    return (word);
	}
      i = i + 1;
    }
  return (word);
}

int	count_char(char *str, int *i)
{
  int	chars;
  int	x;

  x = *i;
  chars = 0;
  while (str[x] != '\0' && is_alnum(str[x]))
    {
      chars = chars + 1;
      x = x + 1;
    }
  return (chars);
}

char	**my_str_to_wordtab(char *str, int x, int y)
{
  char	**wtab;
  int	i;
  int	c;

  i = 0;
  if ((str == NULL)
      || ((wtab = malloc(sizeof(char *) * (count_words(str) + 1))) == NULL))
    return (NULL);
  while (str[i] != '\0' && x <= count_words(str))
    {
      c = count_char(str, &i);
      if (is_alnum(str[i]))
	{
	  if ((wtab[x] = malloc(sizeof(char) * c + 1)) == NULL)
	    return (NULL);
	  while (str[i] != '\0' && is_alnum(str[i]) && y < c)
	    wtab[x][y++] = str[i++];
	  wtab[x++][y] = '\0';
	  y = 0;
	}
      else if (str[i])
      	++i;
    }
  wtab[x] = NULL;
  return (wtab);
}
