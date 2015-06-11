/*
** termcaps.c for 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Wed May 20 11:06:52 2015 leo lzfon
** Last update Sun May 24 20:10:06 2015 leo lzfon
*/

#include <termcap.h>
#include "42sh.h"

int	my_outc(int c)
{
  my_putchar(c);
  return (0);
}

char	*klear_screen(t_system *sys, char *line)
{
  char	*cmd;

  (void)sys;
  if (!(cmd = tgetstr("cl", NULL)))
    return (NULL);
  tputs(cmd, 0, &my_outc);
  aff_prompt(sys);
  return (line);
}

char	unset_termcaps(t_system *sys)
{
  if (tcsetattr(0, TCSANOW, &sys->s_attr) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

char	set_termcaps(t_system *sys)
{
  if (tcsetattr(0, TCSANOW, (&sys->t_attr)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
