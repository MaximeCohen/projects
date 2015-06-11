/*
** autocomp_cut.c for  in /home/agor_m/tests/autocomplete
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Thu May 21 18:03:26 2015 Maxime Agor
** Last update Sun May 24 23:31:12 2015 cohen_h
*/

#include <stdlib.h>
#include <string.h>
#include "42sh.h"

char	*autocomp_getname(char *line)
{
  int	i;
  int	last_dash;

  if (!line)
    return (strdup(""));
  i = 0;
  last_dash = 0;
  while (line[i])
    {
      if (line[i] == '/')
	last_dash = i + 1;
      ++i;
    }
  return (strdup(line + last_dash));
}

char	*autocomp_getpath(char *line)
{
  int	i;
  int	last_dash;
  char	*path;

  if (!line)
    return (strdup("./"));
  i = 0;
  last_dash = 0;
  while (line[i])
    {
      if (line[i] == '/')
	last_dash = i;
      ++i;
    }
  path = strndup(line, last_dash + (line[0] == '/' ? 1 : 0));
  if (!path || strcmp(path, "") == 0)
    {
      if (path)
	free(path);
      return (strdup("."));
    }
  return (path);
}

char	*wordtab_getlast(char **wordtab)
{
  int	i;

  if (!wordtab)
    return (NULL);
  i = 0;
  while (wordtab[i])
    ++i;
  if (!i)
    return (NULL);
  --i;
  return (wordtab[i]);
}

int	contain_path(char *line)
{
  int	i;

  if (!line)
    return (0);
  i = 0;
  while (line[i])
    {
      if (line[i] == '/')
	return (1);
      ++i;
    }
  return (0);
}
