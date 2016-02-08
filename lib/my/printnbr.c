/*
** printnbr.c for nbr in /home/bougon_p/rendu/PSU_2015_my_printf
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Wed Nov  4 13:07:16 2015 Pierre Bougon
** Last update Thu Nov 12 13:00:26 2015 Pierre Bougon
*/

#include "./printf.h"

int		print_bin(va_list ap)
{
  unsigned int	nbr;
  int		i;

  nbr = va_arg(ap, unsigned int);
  i = my_putnbr_base(nbr, "01");
  return (i);
}

int	print_octal(va_list ap)
{
  unsigned int	nbr;
  int		i;

  nbr = va_arg(ap, unsigned int);
  i = my_putnbr_base(nbr, "01234567");
  return (i);
}

int	print_decimal(va_list ap)
{
  int	nbr;
  int	i;

  nbr = va_arg(ap, int);
  i = my_put_nbr(nbr);
  return (i);
}

int	print_hexa(va_list ap)
{
  unsigned int	nbr;
  int		i;

  nbr = va_arg(ap, unsigned int);
  i = my_putnbr_base(nbr, "0123456789abcdef");
  return (i);
}

int	print_HEXA(va_list ap)
{
  unsigned int	nbr;
  int		i;

  nbr = va_arg(ap, unsigned int);
  i = my_putnbr_base(nbr, "0123456789ABCDEF");
  return (i);
}
