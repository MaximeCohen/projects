/*
** exit.c for  in /home/agor_m/RenduTek1/minishell
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Sun Feb  1 17:52:21 2015 Maxime Agor
** Last update Fri May 22 17:48:07 2015 Maxime Agor
*/

#include "42sh.h"

int	my_exit(t_system *sys)
{
  sys->exit.exit = true;
  sys->exit.value = (sys->cmd->cmd && sys->cmd->cmd[1]) ?
    my_getnbr(sys->cmd->cmd[1]) : 0;
  return (0);
}
