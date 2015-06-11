/*
** globing.c for 42sh in /home/cohen_h/Bureau/rendu/B2/B2-Systeme_Unix/PSU_2014_42sh
**
** Made by cohen_h
** Login   <cohen_h@epitech.net>
**
** Started on  Sat May 23 18:53:28 2015 cohen_h
** Last update Sun May 24 22:43:44 2015 cohen_h
*/

#include <glob.h>
#include "42sh.h"

int		add_elem_glob(char **newstr, glob_t glb)
{
  unsigned int	i;
  char		*tmp;

  i = 0;
  if (*newstr == NULL)
    {
      if (!(*newstr = malloc((strlen(glb.gl_pathv[i]) + 1) * sizeof(char))))
	return (EXIT_FAILURE);
      strcpy(*newstr, glb.gl_pathv[i]);
      ++i;
    }
  while (i < glb.gl_pathc)
    {
      tmp = *newstr;
      if (!(*newstr = my_strdog(tmp, " ")))
	return (EXIT_FAILURE);
      free(tmp);
      tmp = *newstr;
      if  (!(*newstr = my_strdog(tmp, glb.gl_pathv[i])))
	return (EXIT_FAILURE);
      free(tmp);
      ++i;
    }
  return (EXIT_SUCCESS);
}

int	add_elem_string(char **newstr, char *elem)
{
  char	*tmp;

  if (*newstr == NULL)
    {
      if (!(*newstr = malloc((strlen(elem) + 1) * sizeof(char))))
	return (EXIT_FAILURE);
      strcpy(*newstr, elem);
    }
  else
    {
      tmp = *newstr;
      if (!(*newstr = my_strdog(tmp, " ")))
	return (EXIT_FAILURE);
      free(tmp);
      tmp = *newstr;
      if  (!(*newstr = my_strdog(tmp, elem)))
	return (EXIT_FAILURE);
      free(tmp);
    }
  return (EXIT_SUCCESS);
}

int	func_glob(char **newstr, char *elem)
{
  int		status;
  glob_t	glb;

  status = glob(elem, 0, NULL, &glb);
  if (status == GLOB_NOSPACE || status == GLOB_ABORTED)
    return (EXIT_FAILURE);
  else if (status == GLOB_NOMATCH)
    {
      if (add_elem_string(newstr, elem) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    {
      if (add_elem_glob(newstr, glb) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  globfree(&glb);
  return (EXIT_SUCCESS);
}

char	*my_globing(char *str)
{
  char	**table;
  char	*newstr;
  int	i;

  if (!(table = get_argv(str, " ")))
    return (NULL);
  i = 0;
  newstr = NULL;
  while (table[i])
    {
      if (func_glob(&newstr, table[i]) == EXIT_FAILURE)
	return (NULL);
      ++i;
    }
  free_wordtab(table);
  free(str);
  return (newstr);
}
