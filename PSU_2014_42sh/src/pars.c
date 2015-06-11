/*
** pars.c for pars 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Thu May  7 12:30:16 2015 leo lzfon
** Last update Sun May 24 23:10:52 2015 cohen_h
*/

#include "42sh.h"

char	is_separator_char(char c)
{
  int	i;
  char	*index;

  i = 0;
  index = SEPARATOR_CHARS;
  while (i < my_strlen(SEPARATOR_CHARS))
    {
      if (c == index[i])
	return (EXIT_SUCCESS);
      ++i;
    }
  return (EXIT_FAILURE);
}

char		get_between_separators(t_system *sys, char *line, int *i)
{
  char		*between;
  char		**cmd_tab;
  int		j;
  t_bool	quote;

  j = 0;
  quote = false;
  if ((between = malloc(sizeof(char) * (my_strlen(line) + 1))) == NULL)
    return (EXIT_FAILURE);
  while (line && line[*i] && (is_separator_char(line[*i]) || quote))
    {
      if (line[*i] == '"')
	quote = quote ? false : true;
      between[j] = line[*i];
      ++j;
      ++*i;
    }
  between[j] = '\0';
  if (quote)
    return (EXIT_FAILURE);
  cmd_tab = get_argv(between, DELIM);
  if (cmd_tab && cmd_tab[0])
    sys->cmd = put_in_cmd_list(cmd_tab, sys->cmd, NOTHING);
  free(between);
  return (EXIT_SUCCESS);
}

char	determine_separator(t_system *sys, char *sep)
{
  char	*sep_tab[8];
  int	i;

  i = 0;
  sep_tab[0] = ";";
  sep_tab[1] = "|";
  sep_tab[2] = ">";
  sep_tab[3] = ">>";
  sep_tab[4] = "<";
  sep_tab[5] = "<<";
  sep_tab[6] = "&&";
  sep_tab[7] = "||";
  while (i < 8)
    {
      if (strcmp(sep, sep_tab[i]) == 0)
	{
	  sys->cmd = put_in_cmd_list(NULL, sys->cmd, i);
	  return (EXIT_SUCCESS);
	}
      ++i;
    }
  free(sep);
  return (EXIT_FAILURE);
}

char	get_separators(t_system *sys, char *line, int *i)
{
  char	*separator_str;
  int	j;

  j = 0;
  if ((separator_str = malloc(sizeof(char) * (my_strlen(line) + 1))) == NULL)
    return (EXIT_FAILURE);
  while (line && line[*i] && is_separator_char(line[*i]) == EXIT_SUCCESS)
    {
      separator_str[j] = line[*i];
      ++*i;
      ++j;
    }
  separator_str[j] = '\0';
  if (determine_separator(sys, separator_str) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  free(separator_str);
  return (EXIT_SUCCESS);
}

char	pars_line(t_system *sys, char *line)
{
  int	i;

  i = 0;
  while (line && line[i])
    {
      get_between_separators(sys, line, &i);
      if (!line[i])
	return (EXIT_SUCCESS);
      if (get_separators(sys, line, &i))
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
