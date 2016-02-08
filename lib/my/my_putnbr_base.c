/*
** my_putnbr_base.c for putbase in /home/bougon_p/rendu/PSU_2015_my_printf
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Mon Nov  9 16:46:18 2015 Pierre Bougon
** Last update Thu Nov 12 12:57:51 2015 Pierre Bougon
*/

#include "./printf.h"

int	my_calc_nbrbase(unsigned int nbr, char *base)
{
  int	i;

  i = 1;
  if (nbr > base[my_strlen(base)])
    i += my_calc_nbrbase(nbr / my_strlen(base), base);
  if (nbr > base[0] - 48)
    my_putchar(base[(nbr % my_strlen(base))]);
  return (i);
}

int	my_putnbr_base(unsigned int nbr, char *base)
{
  int	i;

  i = 0;
  if (nbr == base[0] - 48)
    {
      my_putchar(base[0]);
      return (0);
    }
  i += my_calc_nbrbase(nbr, base);
  return (i - 1);
}
