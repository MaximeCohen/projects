/*
** get_dollar.c for get_dollar in /home/huet_f/rendu/PSU/PSU_2014_42sh
**
** Made by Florian Huet
** Login   <huet_f@epitech.net>
**
** Started on  Fri May 22 21:19:53 2015 Florian Huet
** Last update Sun May 24 22:06:13 2015 Florian Huet
*/

#include "42sh.h"

char	my_is_alnum(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
      (c >= 'A' && c <= 'Z'))
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

char	*get_begin(char *str)
{
  int	i;
  char	*tmp;

  i = 0;
  if (str[i] == '$')
    return (NULL);
  if ((tmp = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] && str[i] != '$')
    {
      tmp[i] = str[i];
      ++i;
    }
  tmp[i] = '\0';
  return (tmp);
}

char	*get_end(char *str)
{
  int	i;
  int	x;
  char	*tmp;

  i = 0;
  x = 0;
  while (str[i] && str[i] != '$')
    ++i;
  ++i;
  while (str[i] && !(my_is_alnum(str[i])))
    ++i;
  if (str[i] == '\0')
    return (NULL);
  if ((tmp = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      tmp[x] = str[i];
      ++i;
      ++x;
    }
  tmp[x] = '\0';
  return (tmp);
}

char	*get_mid(char *str)
{
  int	i;
  int	x;
  char	*tmp;

  i = 0;
  x = 0;
  if ((tmp = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] && str[i] != '$')
    ++i;
  ++i;
  if (str[i] == '\0')
    return (NULL);
  while (str[i] && !(my_is_alnum(str[i])))
    {
      tmp[x] = str[i];
      ++i;
      ++x;
    }
  tmp[x] = '\0';
  return (tmp);
}
