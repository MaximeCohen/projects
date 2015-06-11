/*
** without_termcaps.c for 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Sun May 24 17:39:30 2015 leo lzfon
** Last update Sun May 24 18:05:53 2015 leo lzfon
*/

#include "42sh.h"

char	without_termcaps(t_system *sys)
{
  char	*line;

  write(1, "\n( *0*)/ : ", my_strlen("\n( *0*)/ : "));
  while ((line = get_next_line(0)))
    {
      send_line(sys, &line);
    }
  return (EXIT_SUCCESS);
}
