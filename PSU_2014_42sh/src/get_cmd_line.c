/*
** get_cmd_line.c for 42sh in /home/resse_e/save/PSU_2014_42sh.4/src
**
** Made by enzo resse
** Login   <resse_e@epitech.net>
**
** Started on  Sun May 24 11:46:39 2015 enzo resse
** Last update Sun May 24 22:11:14 2015 leo lzfon
*/

#include "42sh.h"

char	check_separators(t_system *sys)
{
  t_cmd	*tmp;

  if (sys->cmd && sys->cmd->separator != NOTHING)
    return (EXIT_FAILURE);
  tmp = sys->cmd;
  while (tmp)
    {
      if (tmp->next &&
	  tmp->separator != NOTHING  &&
	  tmp->next->separator != NOTHING)
	return (EXIT_FAILURE);
      else if (!tmp->next && tmp->separator != NOTHING)
	return (EXIT_FAILURE);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

char	*do_special_case(t_system *sys, char *buffer, char *line)
{
  char	*(*fptr_tab[5])();
  char	(*index[5])();
  int	i;

  index[0] = &check_backspace;
  index[1] = &check_ctr_l;
  index[2] = &check_tabulation;
  index[3] = &is_arrow;
  index[4] = &is_echo_pipe;
  fptr_tab[0] = &decrease_line;
  fptr_tab[1] = &klear_screen;
  fptr_tab[2] = &autocomplete;
  fptr_tab[3] = &manage_arrow;
  fptr_tab[4] = &do_echo_pipe;
  i = 0;
  while (i < 5)
    {
      if (!index[i](buffer))
	return (fptr_tab[i](sys, line, buffer));
      ++i;
    }
  return (NULL);
}

void	reset_line(t_system *sys, char **line)
{
  free(*line);
  free_cmd(sys->cmd);
  sys->cmd = NULL;
  *line = NULL;
}

char	send_line(t_system *sys, char **line)
{
  write(1, "\n", 1);
  reset_history(sys);
  *line = switch_line(sys, *line);
  if (pars_line(sys, *line))
    {
      reset_line(sys, line);
      aff_prompt(sys);
      return (EXIT_FAILURE);
    }
  determine_cmd(sys);
  if (check_separators(sys))
    {
      reset_line(sys, line);
      aff_prompt(sys);
      return (EXIT_FAILURE);
    }
  unset_termcaps(sys);
  controle(sys);
  set_termcaps(sys);
  aff_prompt(sys);
  reset_line(sys, line);
  return (EXIT_SUCCESS);
}

char	get_cmd_line(t_system *sys)
{
  char	buffer[BUFFER_SIZE];
  char	*line;
  int	len;

  line = NULL;
  while (!sys->exit.exit)
    {
      if ((len = read(0, buffer, BUFFER_SIZE)) == -1)
	return (EXIT_FAILURE);
      buffer[len] = 0;
      if (!is_special_case(buffer))
	line = do_special_case(sys, buffer, line);
      else if (buffer[0] == '\n' || buffer[0] == 4)
	buffer[0] == 4 ? (!line ? sys->exit.exit = true :		\
			  send_line(sys, &line)) : send_line(sys, &line);
      else
	{
	  if (buffer[0] == 0)
	    sys->exit.exit = true;
	  line = append_to_line(buffer, line);
	  write(1, buffer, my_strlen(buffer));
	}
    }
  return (EXIT_SUCCESS);
}
