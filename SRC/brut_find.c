/*
** brut_find.c for find in /home/bougon_p/rendu/CPE_2015_BSQ
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Wed Dec  2 21:01:31 2015 Pierre Bougon
** Last update Fri Dec 11 01:48:32 2015 Pierre Bougon
*/

#include "../include/bsq.h"

int	calc_square(int **map, int x, int y)
{
  int	diag;
  int	top;
  int	left;

  if ((x == 0 || y == 0) && map[y][x] != 0)
    return (1);
  else if (map[y][x] == 0)
    return (0);
  diag = map[y - 1][x - 1];
  top = map[y - 1][x];
  left = map[y][x - 1];
  if (diag <= top && diag <= left)
    return (diag + 1);
  else if (top <= diag && top <= left)
    return (top + 1);
  else if (left <= top && left <= diag)
    return (left + 1);
  return (0);
}

int		max_square(int **map, t_fileinfo *finfo)
{
  int		i;
  int		j;
  int		max_diag;

  i = 0;
  j = 0;
  max_diag = 0;
  while (j < finfo->nb_lines)
    {
      while (i < finfo->nb_col)
	{
	  map[j][i] = calc_square(map, i, j);
	  max_diag = (map[j][i] > max_diag) ? map[j][i] : max_diag;
	  i++;
	}
      i = 0;
      j++;
    }
  return (max_diag);
}
