/*
** main.c for  in /home/agor_m/tests/PSU_2014_42sh/src
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Sun May 24 15:01:51 2015 Maxime Agor
** Last update Sun May 24 23:08:49 2015 enzo resse
*/

#include "42sh.h"

char			init_termcaps(t_system *sys)
{
  struct termios	t_attr;
  char			*term_name;

  term_name = my_getenv(sys->env, "TERM");
  if (term_name)
    tgetent(NULL, term_name);
  if (tcgetattr(0, &t_attr) == - 1)
    return (EXIT_FAILURE);
  sys->t_attr = t_attr;
  sys->s_attr = t_attr;
  sys->t_attr.c_lflag &= ~ICANON;
  sys->t_attr.c_lflag &= ~ECHO;
  sys->t_attr.c_cc[VMIN] = 1;
  sys->t_attr.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSAFLUSH, &sys->t_attr) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

char	init_sys(t_system *sys, t_hist **root, char **env)
{
  sys->env = NULL;
  sys->path = NULL;
  sys->cmd = NULL;
  sys->alias = NULL;
  sys->exit.exit = false;
  sys->exit.value = 0;
  if ((*root = malloc(sizeof(**root))) == NULL)
    {
      printf("Malloc error\n");
      return (-1);
    }
  (*root)->next = NULL;
  (*root)->line = NULL;
  (*root)->prev = NULL;
  (*root)->id = -1;
  save_env_and_path(sys, env);
  return (init_termcaps(sys));
}

int			main(int ac, char **av, char **env)
{
  t_system		sys;

  (void)av;
  (void)ac;
  if (signal(SIGINT, &handle_sig) == SIG_ERR)
    return (EXIT_FAILURE);
  if (init_sys(&sys, &sys.history, env) == -1)
    return (EXIT_FAILURE);
  get_sys(&sys);
  process_conf_file(&sys);
  aff_prompt(&sys);
  get_cmd_line(&sys);
  unset_termcaps(&sys);
  free_all(&sys);
  if (sys.exit.exit == true)
    return (sys.exit.value);
  return (EXIT_SUCCESS);
}
