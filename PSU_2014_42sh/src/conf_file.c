/*
** conf_file.c for 42sh in /home/resse_e/PSU_2014_42sh/src
**
** Made by enzo resse
** Login   <resse_e@epitech.net>
**
** Started on  Sun May 24 19:20:51 2015 enzo resse
** Last update Sun May 24 21:58:49 2015 Florian Huet
*/

#include "42sh.h"

char	send_conf_line(t_system *sys, char **line)
{
  reset_history(sys);
  if (*line)
    save_line(sys, *line);
  *line = replace_cmd(sys, *line, LOOP_TURN, 0);
  if (!(*line = my_globing(*line)))
    return (EXIT_FAILURE);
  if (pars_line(sys, *line))
    {
      reset_line(sys, line);
      return (EXIT_FAILURE);
    }
  determine_cmd(sys);
  if (check_separators(sys))
    {
      reset_line(sys, line);
      return (EXIT_FAILURE);
    }
  unset_termcaps(sys);
  controle(sys);
  set_termcaps(sys);
  reset_line(sys, line);
  return (EXIT_SUCCESS);
}

char	process_conf_file(t_system *sys)
{
  int	fd;
  char	*path;
  char	*line;

  if ((path = malloc(sizeof(char) *
		     (my_strlen(my_getenv(sys->env, "HOME")) + 10))) == NULL)
    {
      printf("\nMalloc error\n");
      return (EXIT_FAILURE);
    }
  sprintf(path, "%s/.42shrc", my_getenv(sys->env, "HOME"));
  if ((fd = open(path, O_RDONLY | O_CREAT, C_RIGHT)) == -1)
    {
      printf("\nOpen error\n");
      return (EXIT_FAILURE);
    }
  while ((line = get_next_line(fd)) != NULL)
    {
      send_conf_line(sys, &line);
      free(line);
    }
  close(fd);
  free(path);
  return (EXIT_SUCCESS);
}
