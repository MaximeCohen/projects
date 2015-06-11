/*
** switch_line.c for 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Sun May 24 18:07:36 2015 leo lzfon
** Last update Sun May 24 22:44:38 2015 leo lzfon
*/

#include "42sh.h"

char	*switch_line(t_system *sys, char *line)
{
  char	*new_line;

  if (line)
    save_line(sys, line);
  line = replace_cmd(sys, line, LOOP_TURN, 0);
  if ((new_line = my_globing(line)))
    {
      line = new_line;
    }
  return (line);
}
