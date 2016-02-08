/*
** print.c for print in /home/bougon_p/rendu/CPE_2015_BSQ/SRC
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Tue Dec  1 14:15:16 2015 Pierre Bougon
** Last update Fri Dec 11 01:49:29 2015 Pierre Bougon
*/

#include "../include/bsq.h"

void	draw_final_map(int **map, t_fileinfo *finfo)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < finfo->nb_lines)
    {
      while (i < finfo->nb_col)
	{
	  if (map[j][i] == 0)
	    my_printf("o");
	  else if (map[j][i] > 0)
	    my_printf(".");
	  else if (map[j][i] == -1)
	    my_printf("x");
	  i++;
	}
      i = 0;
      j++;
      my_printf("\n");
    }
}

void	draw_patern(char **patern, t_fileinfo *finfo)
{
  int   j;
  int   i;

  j = 0;
  i = 0;
  while (j < finfo->nb_lines)
    {
      while (i < finfo->nb_col)
        {
          my_printf("%c", patern[j][i++]);
        }
      my_printf("\n");
      i = 0;
      j++;
    }
}

void	draw_map(int **map, t_fileinfo *finfo)
{
  int   j;
  int   i;

  j = 0;
  i = 0;
  while (j < finfo->nb_lines)
    {
      while (i < finfo->nb_col)
        {
          my_printf("%d ", map[j][i++]);
        }
      my_printf("\n");
      i = 0;
      j++;
    }
}
