/*
** printothers.c for print in /home/bougon_p/rendu/PSU_2015_my_printf
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Mon Nov  9 13:28:07 2015 Pierre Bougon
** Last update Fri Nov 13 14:47:42 2015 Pierre Bougon
*/

#include "./printf.h"

int	print_nbchar(va_list ap, int countchar)
{
  int	*ptr;

  ptr = va_arg(ap, int *);
  *ptr = countchar;
  return (0);
}

int		print_pc(va_list ap)
{
  unsigned char	c;

  c = '%';
  my_putchar(c);
  return (1);
}

int	print_unint(va_list ap)
{
  unsigned int	nbr;
  int		i;

  nbr = va_arg(ap, unsigned int);
  i = my_putnbr_base(nbr, "0123456789");
  return (i);
}

int	print_nothing(va_list ap)
{
  return (0);
}
