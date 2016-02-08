/*
** init.c for init in /home/bougon_p/rendu/PSU_2015_my_printf
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Wed Nov  4 11:58:36 2015 Pierre Bougon
** Last update Mon Nov 16 10:57:50 2015 Pierre Bougon
*/

#include <stdlib.h>
#include "./printf.h"

int	free_init(t_tab *arg)
{
  free(arg);
  return (0);
}

int	init_flags(t_tab *arg)
{
  char	*flag;

  if ((flag = malloc(sizeof(char) * 14)) == NULL)
      return (1);
  flag[0] = 'b';
  flag[1] = 'o';
  flag[2] = 'd';
  flag[3] = 'i';
  flag[4] = 'x';
  flag[5] = 'X';
  flag[6] = 'c';
  flag[7] = 's';
  flag[8] = 'S';
  flag[9] = 'u';
  flag[10] = 'p';
  flag[11] = 'n';
  flag[12] = '%';
  arg->flags = flag;
  return (0);
}

int	init_tab(t_tab *arg)
{
  int   (**targ)(va_list);

  if ((targ = malloc(sizeof(t_tab) * 15)) == NULL)
    return (1);
  targ[0] = &print_bin;
  targ[1] = &print_octal;
  targ[2] = &print_decimal;
  targ[3] = &print_decimal;
  targ[4] = &print_hexa;
  targ[5] = &print_HEXA;
  targ[6] = &print_char;
  targ[7] = &print_string;
  targ[8] = &print_strhide;
  targ[9] = &print_unint;
  targ[10] = &print_ptr;
  targ[12] = &print_pc;
  targ[13] = &print_pc;
  targ[14] = &print_nothing;
  arg->targ = targ;
  return (0);
}
