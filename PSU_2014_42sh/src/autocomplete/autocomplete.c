/*
** autocomplete.c for  in /home/agor_m/tests/autocomplete
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Thu May 21 19:11:19 2015 Maxime Agor
** Last update Sun May 24 23:28:55 2015 cohen_h
*/

#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "42sh.h"

char	*autocomplete_line(char *line, char *autocomp, char *lastword)
{
  char	*new_line;
  char	*name;

  if (count_word(autocomp, " \t\n") != 2)
    {
      if (autocomp)
	printf("\n%s\n", autocomp);
      return (line);
    }
  if (!line || !autocomp)
    return (line);
  if (strlen(autocomp) > 1)
    {
      if (!(name = autocomp_getname(lastword)))
	return (line);
      autocomp[strlen(autocomp) - 1] = '\0';
      if (!(new_line = my_strdog(line, autocomp + strlen(name))))
	return (line);
      free(autocomp);
      free(line);
      free(name);
      return (new_line);
    }
  free(autocomp);
  return (line);
}

char		*autocomplete_onefolder(char *folder, char *file)
{
  DIR		*dir;
  struct dirent	*buf;
  char		*to_return;
  char		*tmp;

  if (!folder || !file || !(to_return = strdup("")))
    return (NULL);
  if (!(dir = opendir(folder)))
    return (NULL);
  tmp = NULL;
  while ((buf = readdir(dir)) && to_return)
    {
      if (strncmp(file, buf->d_name, strlen(file)) == 0)
	{
	  if (!(tmp = my_strdog(to_return, buf->d_name)))
	    return (NULL);
	  free(to_return);
	  if (!(to_return = my_strdog(tmp, buf->d_type == DT_DIR ? "/ " : " ")))
	    return (NULL);
	  free(tmp);
	}
    }
  closedir(dir);
  return (to_return);
}

char	*autocomplete_command(char *command, char **path)
{
  char	*print;
  char	*tmp;
  char	*last_print;
  int	i;

  if (!(print = strdup("")))
    return (NULL);
  i = 0;
  while (path[i] && print)
    {
      tmp = NULL;
      last_print = NULL;
      print = my_strdog((last_print = print),
			(tmp = autocomplete_onefolder(path[i], command)));
      ++i;
      if (last_print && last_print != print)
	free(last_print);
      if (tmp)
  	free(tmp);
    }
  return (print);
}

char	*autocomplete_file(char *line)
{
  char	*print;
  char	*file;
  char	*path;
  char	**wordtab;

  wordtab = get_argv(line, " \t\n");
  if (!wordtab)
    return (NULL);
  if (!(file = autocomp_getname(wordtab[count_word(line, " \t\n") - 1])))
    return (NULL);
  if (!(path = autocomp_getpath(wordtab[count_word(line, " \t\n") - 1])))
    return (NULL);
  print = autocomplete_onefolder(path, file);
  free_wordtab(wordtab);
  free(file);
  free(path);
  return (print);
}

char	*autocomplete(t_system *sys, char *line, char *buffer)
{
  char	**wordtab;
  char	*l;
  char	*new_line;

  (void)buffer;
  if (!line || !sys)
    return (NULL);
  if (!(wordtab = get_argv(line, " \t\n")))
    return (NULL);
  if (count_word(line, " \t\n") == 1 && !contain_path(wordtab[0]))
    l = autocomplete_command(wordtab[0], sys->path);
  else
    l = autocomplete_file(line);
  new_line = autocomplete_line(line, l, wordtab[wordtab_len(wordtab) - 1]);
  free_wordtab(wordtab);
  clean_line(new_line);
  write(1, new_line, my_strlen(new_line));
  return (new_line);
}
