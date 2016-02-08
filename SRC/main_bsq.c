/*
** main_bsq.c for main in /home/bougon_p/rendu/CPE_2015_BSQ
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Mon Nov 30 16:02:13 2015 Pierre Bougon
** Last update Fri Dec 18 12:06:51 2015 Pierre Bougon
*/

#include "../include/bsq.h"

char	**realloc_patern(t_fileinfo *finfo, char *patern)
{
  char	**new_tab;
  int	j;

  j = 0;
  if ((new_tab = malloc(sizeof(char *) * finfo->nb_lines)) == NULL)
    return (NULL);
  while (j < finfo->nb_lines)
    {
      if ((new_tab[j] = malloc(sizeof(char) * finfo->nb_col + 1)) == NULL)
	return (NULL);
      new_tab[j][finfo->nb_col] = 0;
      j++;
    }
  new_tab[0] = patern;
  return (new_tab);
}

int	free_patern(char **patern, t_fileinfo *finfo)
{
  int	j;

  j = 0;
  while (j < finfo->nb_lines)
    {
      free(patern[j]);
      j++;
    }
  free(patern);
  return (0);
}

int	free_map(int **map, t_fileinfo *finfo)
{
  int	j;

  j = 0;
  while (j < finfo->nb_lines)
    {
      free(map[j]);
      j++;
    }
  free(map);
  return (0);
}

int		main(int ac, char **av)
{
  t_fileinfo	finfo;
  char		**patern;
  int		**map;
  int		fd;
  int		max_diag;

  if (ac != 2)
    {
      my_printf("Usage : \"Program\" \"Map\"\n");
      return (1);
    }
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (1);
  patern = get_patern(fd, &finfo);
  map = create_map(&finfo, patern);
  max_diag = max_square(map, &finfo);
  change_sqrmap(map, &finfo, max_diag);
  draw_final_map(map, &finfo);
  close(finfo.fd);
  free_patern(patern, &finfo);
  free_map(map, &finfo);
  return (0);
}
