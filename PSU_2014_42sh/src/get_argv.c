/*
** my_str_to_wordtab.c for  in /home/agor_m/tests/get_argv
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Fri May  8 10:00:57 2015 Maxime Agor
** Last update Sun May 24 21:28:50 2015 Florian Huet
*/

/*
** This is a my_str_to_wordtab designed not to cut quoted words.
*/

#include <stdlib.h>

char	my_isspace(char c, char *delim)
{
  int	i;

  i = 0;
  if (!delim)
    return (0);
  while (delim[i])
    {
      if (c == delim[i])
	return (1);
      ++i;
    }
  return (0);
}

int	count_word(char *str, char *delim)
{
  int	is_quoted;
  int	i;
  int	nbrword;

  if (!str)
    return (0);
  is_quoted = 0;
  i = 0;
  nbrword = 0;
  while (str[i])
    {
      while (str[i] && my_isspace(str[i], delim))
	++i;
      if (!my_isspace(str[i], delim) && !is_quoted)
	++nbrword;
      if (str[i] == '"')
	is_quoted = is_quoted ? 0 : 1;
      while (str[i] && (!my_isspace(str[i], delim) || is_quoted))
	is_quoted = (str[i++] == '"') ? -(is_quoted - 1) : is_quoted;
    }
  return (nbrword);
}

int	size_word(char *str, int curs, char *delim, int is_quoted)
{
  int	size;

  size = 0;
  while (str[curs] && (!my_isspace(str[curs], delim) || is_quoted))
    {
      is_quoted = (str[curs] == '"') ? -(is_quoted - 1) : is_quoted;
      ++size;
      ++curs;
    }
  return (size);
}

char	*get_word(char *str, int *i, char *delim, int is_quoted)
{
  char	*word;
  int	j;

  j = 0;
  if (!(word = malloc((size_word(str, *i, delim, is_quoted) + 1))))
    return (NULL);
  while (str[*i] && (!my_isspace(str[*i], delim) || is_quoted))
    {
      if (!(str[*i] == '"'))
	{
	  word[j] = str[*i];
	  ++j;
	}
      is_quoted = (str[(*i)++] == '"') ? -(is_quoted - 1) : is_quoted;
    }
  word[j] = 0;
  return (word);
}

char	**get_argv(char *str, char *delim)
{
  char	**wordtab;
  int	i;
  int	elem;
  int	is_quoted;

  is_quoted = 0;
  i = 0;
  elem = 0;
  if (!str)
    return (NULL);
  if (!(wordtab = calloc((count_word(str, delim) + 1) * sizeof(char *),
		     (count_word(str, delim) + 1) * sizeof(char *))))
    return (NULL);
  while (str && str[i])
    {
      while (str[i] && (my_isspace(str[i], delim) || is_quoted))
	is_quoted = (str[i++] == '"') ? -(is_quoted - 1) : is_quoted;
      if ((wordtab[elem++] = get_word(str, &i, delim, is_quoted)) == NULL)
	return (NULL);
      while (str[i] && my_isspace(str[i], delim))
	++i;
    }
  return (wordtab);
}
