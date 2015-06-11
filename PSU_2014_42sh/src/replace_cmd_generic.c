/*
** replace_cmd_generic.c for replace_cmd_generic in /home/huet_f/rendu/PSU/PSU_2014_42sh/src
**
** Made by Florian Huet
** Login   <huet_f@epitech.net>
**
** Started on  Sun May 24 12:09:17 2015 Florian Huet
** Last update Sun May 24 21:22:56 2015 Florian Huet
*/

#include "42sh.h"

char	**replace_between_separators(char *line, int *i)
{
  char	*between;
  char	**cmd_tab;
  int	j;

  j = 0;
  if ((between = malloc(sizeof(char) * (my_strlen(line) + 1))) == NULL)
    return (NULL);
  while (line && line[*i] && is_separator_char(line[*i]) == EXIT_FAILURE)
    {
      between[j] = line[*i];
      ++j;
      ++*i;
    }
  between[j] = '\0';
  cmd_tab = get_argv(between, DELIM);
  free(between);
  return (cmd_tab);
}
