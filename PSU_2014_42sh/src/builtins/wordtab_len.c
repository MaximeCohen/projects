/*
** wordtab_len.c for  in /home/agor_m/RenduTek1/PSU_2014_42sh/src/builtins
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Thu May 14 18:54:34 2015 Maxime Agor
** Last update Sat May 23 15:06:11 2015 Maxime Agor
*/

int	wordtab_len(char **wordtab)
{
  int	l;

  l = 0;
  while (wordtab && wordtab[l])
    ++l;
  return (l);
}
