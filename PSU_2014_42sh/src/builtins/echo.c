/*
** echo.c for  in /home/agor_m/RenduTek1/minishell2
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Wed May 13 14:48:00 2015 Maxime Agor
** Last update Tue May 19 16:24:33 2015 enzo resse
*/

#include "42sh.h"

int	builtin_echo_specials(char c)
{
  if (c == 'n')
    my_putchar('\n');
  else if (c == 't')
    my_putchar('\t');
  else if (c == 'a')
    my_putchar('\a');
  else if (c == 'v')
    my_putchar('\v');
  else
    my_putchar(c);
  return (1);
}

int	builtin_echo_oneword(char *str, int opt_e)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] != '\\')
	my_putchar(str[i]);
      else
	{
	  if (opt_e)
	    builtin_echo_specials(str[i++ + 1]);
	  else
	    my_putchar('\\');
	}
      ++i;
    }
  return (1);
}

int	my_echo(t_system *sys)
{
  int	i;
  int	opt_e;

  opt_e = (wordtab_len(sys->cmd->cmd) > 1 &&
	   strcmp(sys->cmd->cmd[1], "-e") == 0);
  i = opt_e + 1;
  while (i < wordtab_len(sys->cmd->cmd) && sys->cmd->cmd[i])
    {
      builtin_echo_oneword(sys->cmd->cmd[i], opt_e);
      my_putchar(' ');
      ++i;
    }
  my_putchar('\n');
  return (1);
}
