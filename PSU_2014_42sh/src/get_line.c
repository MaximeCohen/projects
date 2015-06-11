/*
** get_line.c for 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Thu May 21 19:01:32 2015 leo lzfon
** Last update Sun May 24 19:03:09 2015 enzo resse
*/

#include "42sh.h"

char	*do_special_case(t_system *sys, char *buffer, char *line)
{
  if (!is_arrow(buffer))
    return (manage_arrow(sys, buffer, line));
  else if (buffer[0] == 127)
    return (decrease_line(line));
}

char	send_line(t_system *sys, char *line)
{
  if (line)
    save_line(sys, line);
  pars_line(sys, line);
  determine_cmd(sys);
  controle(sys);
  *&line = NULL;
  free(line);
  free_cmd(sys->cmd);
  sys->cmd = NULL;
  return (EXIT_SUCCESS);
}

char	get_cmd_line(t_system *sys)
{
  char	buffer[BUFFER_SIZE];
  char	*line;
  int	len;

  line = NULL;
  while (8)
    {
      if ((len = read(0, buffer, BUFFER_SIZE)) == -1)
	return (EXIT_FAILURE);
      buffer[len] = 0;
      if (buffer[0] == 127 || !is_arrow(buffer))
	line = do_special_case(sys, buffer, line);
      else if (buffer[0] == '\n')
	{
	  send_line(sys, line);
	  aff_prompt(sys);
	  reset_history(sys);
	}
      else
	{
	  line = append_to_line(buffer[0], line);
	  write(1, buffer, my_strlen(buffer));
	}
    }
  return (EXIT_FAILURE);
}
