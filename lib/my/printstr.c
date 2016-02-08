/*
** printstr.c for print in /home/bougon_p/rendu/PSU_2015_my_printf
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Wed Nov  4 13:17:14 2015 Pierre Bougon
** Last update Mon Nov 16 10:29:20 2015 Pierre Bougon
*/

#include "./printf.h"
#include <unistd.h>

int	print_char(va_list ap)
{
  char	c;

  c = va_arg(ap, int);
  my_putchar(c);
  return (1);
}

int	print_string(va_list ap)
{
  char	*str;
  int	i;

  str = va_arg(ap, char *);
  if (str == 0)
    {
      my_putstr("(null)");
      return (6);
    }
  i = my_putstr(str);
  return (i);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}

int		print_strhide(va_list ap)
{
  unsigned char	*str;
  int		i;

  str = va_arg(ap, unsigned char *);
  i = my_putfullstr(str);
  return (i);
}
