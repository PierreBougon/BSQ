/*
** tools.c for tools in /home/bougon_p/rendu/PSU_2015_my_printf
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Mon Nov  9 14:12:25 2015 Pierre Bougon
** Last update Mon Nov 16 10:29:46 2015 Pierre Bougon
*/

#include "./printf.h"
#include <stdarg.h>
#include <unistd.h>

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i++] != 0);
  return (i - 1);
}

int	check_zero(int nb)
{
  int	check;

  my_putchar('\\');
  check = 1;
  if (nb == 0)
    {
      my_putstr("000");
      check += 3;
    }
  else if (nb < 8)
    {
      my_putstr("00");
      check += 2;
    }
  else if (nb < 100)
    {
      my_putstr("0");
      check += 1;
    }
  return (check);
}

int	my_putfullstr(unsigned char *str)
{
  int	nb;
  int	i;
  int	check;

  i = 0;
  check = 0;
  while (str[i] != 0)
    {
      if (str[i] <= 127 && str[i] > 32)
	{
	  write(1, &str[i], 1);
	  check++;
	}
      else
	{
	  nb = str[i];
	  check += check_zero(nb);
	  check += my_putnbr_base(nb, "01234567");
	}
      i++;
    }
  return (check);
}

int	format_star(int nbspace, va_list ap, int j, int i)
{
  nbspace = va_arg(ap, int);
  while (++j < nbspace)
    my_putchar(' ');
  return (i + 1);
}
