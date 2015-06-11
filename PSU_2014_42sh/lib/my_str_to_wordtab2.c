/*
** my_str_to_wordtab.c for  in /home/agor_m/tests/strtowordtab
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Tue Feb 24 01:37:39 2015 Maxime Agor
** Last update Tue May 19 20:01:18 2015 Florian Huet
*/

#include <unistd.h>
#include <stdlib.h>

char	wordtab_is_space(char c, char *spaces)
{
  int	i;

  i = 0;
  if (!spaces)
    return (0);
  while (spaces[i])
    {
      if (c == spaces[i])
	return (1);
      ++i;
    }
  return (0);
}

char	*wordtab_dupword(char *str, char *spaces)
{
  int	i;
  int	j;
  char	*dupped;

  i = 0;
  j = 0;
  if (!str)
    return (0);
  while (str[i] && !wordtab_is_space(str[i], spaces))
    ++i;
  if (!(dupped = malloc(sizeof(char) * (i + 1))))
    return (0);
  while (j < i)
  {
    dupped[j] = str[j];
    ++j;
  }
  dupped[i] = '\0';
  return (dupped);
}

int	wordtab_words_number(char *str, char *spaces)
{
  int	pos;
  int	number;

  number = 0;
  pos = 0;
  if (!str)
    return (0);
  if (!spaces)
    return (1);
  while (wordtab_is_space(str[pos], spaces))
    ++pos;
  while (str[pos])
    {
      if (!wordtab_is_space(str[pos], spaces) &&
	  (pos == 0 || wordtab_is_space(str[pos - 1], spaces)) &&
	  (!(str[pos] != '\0' && str[pos + 1] == '\0')))
	++number;
      ++pos;
    }
  return (number);
}

char	**my_str_to_wordtab2(char *str, char *spaces)
{
  char	**wordtab;
  int	pos;
  int	word;
  int	max_word;

  if (!str)
    return (NULL);
  pos = 0;
  word = 0;
  max_word = wordtab_words_number(str, spaces);
  if (!(wordtab = malloc(sizeof(char *) * (max_word + 1))))
    return ((void *)(0 * (long)(write(2, "Memory allocation error\n", 24))));
  while (wordtab_is_space(str[pos], spaces))
    ++pos;
  while (word < max_word)
    {
      if (!wordtab_is_space(str[pos], spaces) &&
	  (pos == 0 || wordtab_is_space(str[pos - 1], spaces)))
	if (!(wordtab[word++] = wordtab_dupword(str + pos, spaces)))
	  return (wordtab);
      ++pos;
    }
  wordtab[max_word] = NULL;
  return (wordtab);
}
