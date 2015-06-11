/*
** frees.c for  in /home/agor_m/tests/autocomplete
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Fri May 22 00:59:41 2015 Maxime Agor
** Last update Fri May 22 01:03:44 2015 Maxime Agor
*/

#include <stdlib.h>

void	free_wordtab(char **wordtab)
{
  int	i;

  if (!wordtab)
    return ;
  i = 0;
  while (wordtab[i])
    free(wordtab[i++]);
  free(wordtab);
}
