/*
** my_printf.c for printf in /home/bougon_p/rendu/PSU_2015_my_printf
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Wed Nov  4 09:23:56 2015 Pierre Bougon
** Last update Sun Nov 29 23:21:15 2015 Pierre Bougon
*/

#include <stdlib.h>
#include "./printf.h"

int	check_type(char c, char *flags, va_list ap, int countchar)
{
  int	numflag;

  numflag = 0;
  while (c != flags[numflag])
    {
      numflag++;
      if (numflag == 11 && c == 'n')
	{
	  print_nbchar(ap, countchar);
	  return (14);
	}
      if (numflag > 13)
	{
	  my_putchar('%');
	  my_putchar(c);
	  return (14);
	}
    }
  return (numflag);
}

int	get_spaces(const char *str, int *k, va_list ap)
{
  int	i;
  int	nbspace;
  char	*nb;
  int	j;

  i = *k;
  j = 0;
  if ((nb = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (-1);
  nb[0] = 0;
  nb[my_strlen(str)] = 0;
  if (str[i] == '*')
    *k = format_star(nbspace, ap, j, i);
  else
    {
      while (str[i] >= '0' && str[i] <= '9')
	nb[j++] = str[i++];
      nbspace = my_getnbr(nb);
      while (nbspace-- > 0)
	my_putchar(' ');
      *k = i;
    }
  free(nb);
  return (j);
}

int	clean_spaces(const char *str, int i)
{
  while (str[i] == ' ')
    {
      if (str[i + 1] != ' ' && str[i + 1] != 'c' && str[i + 1] != 'r'
	  && str[i + 1] != '%')
	my_putchar(' ');
      i++;
    }
  return (i);
}

int	check_the_string(va_list ap, const char *str, t_tab *arg)
{
  int	i;
  int	countchar;

  i = 0, countchar = 0;
  while (str[i] != 0)
    {
      if (str[i] == '%' && str[i + 1] == 0)
	return (countchar);
      else if (str[i] == '%')
	{
	  i++;
	  i = clean_spaces(str, i);
	  if ((countchar += get_spaces(str, &i, ap)) == -1)
	    return (-1);
	  countchar += arg->targ[check_type(str[i],
					    arg->flags, ap, countchar)](ap);
	}
      else if (str[i] != 0)
	countchar += my_putchar(str[i]);
      i++;
    }
  return (countchar);
}

int		my_printf(const char *str, ...)
{
  t_tab		arg;
  va_list	ap;
  int		countchar;

  if (init_tab(&arg) == 1)
    return (1);
  if (init_flags(&arg) == 1)
    return (1);
  va_start(ap, str);
  if (str[0] == '%' && str[1] == 0)
    return (-1);
  if ((countchar = check_the_string(ap, str, &arg)) == -1)
    return (-1);
  va_end(ap);
  free_init(arg);
  return (countchar);
}
