/*
** replace_cmd.c for replace_cmd in /home/huet_f/rendu/PSU/PSU_2014_42sh
**
** Made by Florian Huet
** Login   <huet_f@epitech.net>
**
** Started on  Sun May 24 22:50:04 2015 Florian Huet
** Last update Sun May 24 23:21:19 2015 enzo resse
*/

#include "42sh.h"

char		*check_alias(t_alias *list, char *str)
{
  t_alias	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (!(strcmp(tmp->name, str)))
	return (tmp->value);
      tmp = tmp->next;
    }
  return (NULL);
}

char	is_dollar(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '$')
	return (EXIT_SUCCESS);
      ++i;
    }
  return (EXIT_FAILURE);
}

char		*check_dollar(char **env, char *str)
{
  char		*begin;
  char		*m;
  char		*end;
  char		*tmp;

  if (!is_dollar(str))
    {
      begin = get_begin(str);
      m = get_mid(str);
      end = get_end(str);
      if (my_getenv(env, m) == NULL)
	{
	  printf("\n%s: Undefined variable", m);
	  free_dollar(begin, m, end);
	  return (strdup(""));
	}
      if ((tmp = malloc(sizeof(char) * (my_strlen(str)
					+ my_strlen(my_getenv(env, m))))) == 0)
	return (NULL);
      sprintf(tmp, "%s%s%s", begin ? begin : "", m &&
	      my_getenv(env, m) ? my_getenv(env, m) : "", end ? end : "");
      free_dollar(begin, m, end);
      return (tmp);
    }
  return (NULL);
}

char	*replace_dollar(t_system *sys, char **words, char *replace, char *line)
{
  int	i;

  i = 0;
  while (words && words[i])
    {
      if ((replace = check_dollar(sys->env, words[i])) != NULL)
	line = replace_line(line, words[i], replace, 0);
      ++i;
      free(replace);
    }
  return (line);
}

char	*replace_cmd(t_system *sys, char *line, int turn_nbr, int x)
{
  char	*replace;
  char	**words;
  int	n;
  int	last_n;

  replace = NULL;
  if (line == NULL)
    return (NULL);
  while (x < turn_nbr)
    {
      n = 0;
      while (line[n])
	{
	  last_n = n;
	  words = replace_between_separators(line, &n);
	  if ((replace = check_alias(sys->alias, words[0])) != NULL)
	    line = replace_line(line, words[0], replace, last_n);
	  line = replace_dollar(sys, words, replace, line);
	  while (line[n] && !is_separator_char(line[n]))
	    ++n;
	  free_wordtab(words);
	}
      ++x;
    }
  return (line);
}
