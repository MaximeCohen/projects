/*
** my_strdog.c for  in /home/agor_m/RenduTek1/minishell/lib/my
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Fri Jan 23 13:57:35 2015 Maxime Agor
** Last update Fri May 22 17:01:55 2015 Maxime Agor
*/

#include <stdlib.h>
#include <string.h>

char	*my_strdog(char *str1, char *str2)
{
  char	*final;
  int	i;

  i = 0;
  if (!str1 || !str2)
    return (str1);
  if (!(final = malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char))))
    return (NULL);
  while ((unsigned int)(i) < strlen(str1) + strlen(str2) + 1)
    final[i++] = '\0';
  strcpy(final, str1);
  strcpy(final + strlen(str1), str2);
  return (final);
}
