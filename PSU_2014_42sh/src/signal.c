/*
** signal.c for signal 42sh in /home/lafon_l/rendu/PSU_2014_42sh
**
** Made by leo lzfon
** Login   <lafon_l@epitech.net>
**
** Started on  Thu May  7 11:10:58 2015 leo lzfon
** Last update Sun May 24 20:36:13 2015 leo lzfon
*/

#include <unistd.h>
#include "42sh.h"

void	handle_sig(int sig)
{
  (void)sig;
  my_putstr("\n");
  aff_prompt(get_sys(NULL));
  set_termcaps(get_sys(NULL));
}
