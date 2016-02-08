/*
** map.c for create map in /home/bougon_p/rendu/CPE_2015_BSQ
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Tue Dec  1 15:34:27 2015 Pierre Bougon
** Last update Fri Dec 18 12:06:37 2015 Pierre Bougon
*/

#include "../include/bsq.h"

int	draw_sqrmap(int **map, int x, int y, int max_diag)
{
  int	lastx;
  int	lasty;
  int	i;

  lastx = x + max_diag;
  lasty = y + max_diag;
  i = x;
  while (y < lasty)
    {
      while (x < lastx)
	{
	  map[y][x] = -1;
	  x++;
	}
      x = i;
      y++;
    }
  return (0);
}

int	change_sqrmap(int **map, t_fileinfo *finfo, int max_diag)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < finfo->nb_lines && map[j][i] != max_diag)
    {
      while (i < finfo->nb_col && map[j][i] != max_diag)
	{
	  i++;
	}
      if (i + 1 <= finfo->nb_col && map[j][i] == max_diag)
	break;
      i = 0;
      j++;
    }
  draw_sqrmap(map, i - max_diag + 1, j - max_diag + 1, max_diag);
  return (0);
}

int	**get_map(t_fileinfo *finfo, char **patern, int **map)
{
  int	j;
  int	i;

  j = 0;
  i = 0;
  while (j < finfo->nb_lines)
    {
      while (i < finfo->nb_col)
	{
	  if (patern[j][i] == '.')
	    map[j][i] = 1;
	  else if (patern [j][i] == 'o')
	    map[j][i] = 0;
	  else
	    {
	      my_printf("Wrong character : %c", patern[j][i]);
	      exit (1);
	    }
	  i++;
	}
      i = 0;
      j++;
    }
  return (0);
}

int	**create_map(t_fileinfo *finfo, char **patern)
{
  int	**map;
  int	j;

  if ((map = malloc(sizeof(int*) * finfo->nb_lines)) == NULL)
    return (NULL);
  j = 0;
  while (j < finfo->nb_lines)
    {
      if ((map[j] = malloc(sizeof(int) * finfo->nb_col)) == NULL)
	return (NULL);
      j++;
    }
  get_map(finfo, patern, map);
  return (map);
}
