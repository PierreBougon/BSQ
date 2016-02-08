/*
** my_putadhexa.c for adptr in /home/bougon_p/rendu/PSU_2015_my_printf
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Tue Nov 10 11:15:35 2015 Pierre Bougon
** Last update Thu Nov 12 12:52:19 2015 Pierre Bougon
*/

#include "./printf.h"

int	calc_adbase(unsigned long nbr, char *base)
{
  int	i;

  i = 1;
  if (nbr / 16 > 1)
    i += calc_adbase(nbr / 16, base);
  if (nbr > 0)
    my_putchar(base[(nbr % 16)]);
  return (i);
}

int			print_ptr(va_list ap)
{
  int			i;
  unsigned long		nbr;
  char			*base;

  base = "0123456789abcdef";
  nbr = va_arg(ap, unsigned long);
  if (nbr == 0)
    {
      my_putstr("(nil)");
      return (1);
    }
   my_putstr("0x");
  i = 0;
  if (nbr == base[0] - 48)
    {
      my_putchar(base[0]);
      return (0);
    }
  i += calc_adbase(nbr, base);
  return (i + 2);
}
