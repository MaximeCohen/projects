/*
** my_getnbr.c for my_getnbr in /home/resse_e/rendu
**
** Made by enzo resse
** Login   <resse_e@epitech.net>
**
** Started on  Thu Oct  2 18:51:32 2014 enzo resse
** Last update Tue May 19 21:22:23 2015 Maxime Agor
*/

int	pos_neg(int nb, int neg)
{
  int	a;

  a = neg % 2;
  if (a == 1)
    {
      nb = - nb;
    }
  return (nb);
}

int	my_getnbr(char *str)
{
  int	a;
  int	neg;
  int	stock;

  a = 0;
  stock = 0;
  neg = 0;
  while ((str[a] > 47 && str[a] < 58) || str[a] == 45 || str[a] == 43)
    {
      if (str[a] > 47 && str[a] < 58)
	stock = stock * 10 + (str[a] - 48);
      if (str[a] == 45)
	++neg;
      ++a;
    }
  stock = pos_neg(stock, neg);
  return (stock);
}
