/*
** check_buffer.c for 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Sat May 23 18:50:24 2015 leo lzfon
** Last update Sun May 24 01:11:21 2015 leo lzfon
*/

#include "42sh.h"

char	check_backspace(char *buffer)
{
  return (buffer && buffer[0] == 127 ? EXIT_SUCCESS : EXIT_FAILURE);
}

char	check_ctr_l(char *buffer)
{
  return (buffer && buffer[0] == 12 ? EXIT_SUCCESS : EXIT_FAILURE);
}

char	check_tabulation(char *buffer)
{
  return (buffer && buffer[0] == 9 ? EXIT_SUCCESS : EXIT_FAILURE);
}

char	is_echo_pipe(char *buffer)
{
  int	i;

  i = 0;
  while (buffer && buffer[i])
    {
      if (i != 0 && buffer[i] == '\n')
	{
	  return (EXIT_SUCCESS);
	}
      ++i;
    }
  return (EXIT_FAILURE);
}

char	is_special_case(char *buffer)
{
  if (!check_backspace(buffer) || !check_ctr_l(buffer))
    return (EXIT_SUCCESS);
  else if (!check_tabulation(buffer) || !is_echo_pipe(buffer)
	   || !is_arrow(buffer))
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}
