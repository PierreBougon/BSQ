/*
** my_put_nbr.c for put nbr in /home/bougon_p
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Tue Oct  6 11:34:10 2015 Pierre Bougon
** Last update Mon Nov 16 10:31:43 2015 Pierre Bougon
*/

#include "./printf.h"

int	my_calc_nbr(int nbr)
{
  int	i;

  i = 1;
  if (nbr >= 10)
    i += my_calc_nbr(nbr / 10);
  if (nbr > 0)
    my_putchar((nbr % 10) + 48);
  return (i);
}

int	my_put_nbr(int nbr)
{
  int	i;

  i = 0;
  if (nbr == -2147483648)
    {
      my_putstr("-2147483648");
      return (11);
    }
  else if (nbr == 0)
    {
      my_putchar('0');
      return (1);
    }
  else if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  i += my_calc_nbr(nbr);
  return (i);
}
