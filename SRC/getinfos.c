/*
** getinfos.c for getfile in /home/bougon_p/rendu/CPE_2015_BSQ/SRC
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Tue Dec  1 14:17:45 2015 Pierre Bougon
** Last update Fri Dec 11 01:48:45 2015 Pierre Bougon
*/

#include "../include/bsq.h"

char	**get_file(t_fileinfo *finfo, char **patern)
{
  int   i;
  int   j;
  int   chk_read;

  i = 0;
  j = 1;
  chk_read = 1;
  while (j < finfo->nb_lines)
    {
      while (i <= finfo->nb_col)
        {
          chk_read = read(finfo->fd, &finfo->buf, 1);
          if (chk_read == -1 || chk_read == 0 ||
              (finfo->buf[0] != '.' && finfo->buf[0] != 'o' &&
               finfo->buf[0] != '\n'))
            {
              write(2, "Wrong file\n", 11);
              exit(1);
            }
          patern[j][i++] = finfo->buf[0];
        }
      i = 0;
      j++;
    }
  return (patern);
}

int	get_nblines(int chk_read, t_fileinfo *finfo)
{
  int   nb_lines;
  int   i;
  char  *nb;

  i = 0;
  if ((nb = malloc(sizeof(char) * 12)) == NULL)
    return (1);
  nb[0] = 0;
  finfo->buf[0] = '0';
  chk_read = 1;
  while (finfo->buf[0] >= '0' && finfo->buf[0] <= '9')
    {
      if ((chk_read = read(finfo->fd, &finfo->buf, 1)) == -1)
        exit (1);
      if (chk_read == 0)
        break;
      nb[i++] = finfo->buf[0];
    }
  nb[i + 1] = 0;
  nb_lines = my_getnbr(nb);
  free (nb);
  return (nb_lines);
}

char	*realloc_firline(char *fir_line, char new_char, int cond)
{
  char	*new_str;
  int	size;
  int	i;

  if (cond == 0)
    {
      fir_line[1] = 0;
      fir_line[0] = new_char;
      return (fir_line);
    }
  size = my_strlen(fir_line);
  if ((new_str = malloc(sizeof(char) * (size + 2))) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      new_str[i] = fir_line[i];
      i++;
    }
  new_str[size + 1] = 0;
  new_str[size] = new_char;
  free(fir_line);
  return (new_str);
}

char	*get_firstline(t_fileinfo *finfo, char *fir_line)
{
  int   i;
  int   chk_read;

  chk_read = 1;
  i = 0;
  finfo->buf[0] = 'Y';
  while (finfo->buf[0] != '\n' || chk_read == 0)
    {
      if ((chk_read = read(finfo->fd, &finfo->buf, 1)) == -1)
        exit (1);
      if (finfo->buf[0] == '\n' || chk_read == 0)
        break;
      fir_line = realloc_firline(fir_line, finfo->buf[0], i);
      i++;
    }
  finfo->nb_col = i;
  return (fir_line);
}

char		**get_patern(int fd, t_fileinfo *finfo)
{
  char          **patern;
  char          *fir_line;
  int           chk_read;

  if ((fir_line = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  fir_line[0] = '.';
  fir_line[1] = 0;
  finfo->fd = fd;
  chk_read = 1;
  finfo->buf[1] = 0;
  finfo->nb_lines = get_nblines(chk_read, finfo);
  fir_line = get_firstline(finfo, fir_line);
  patern = realloc_patern(finfo, fir_line);
  patern = get_file(finfo, patern);
  return (patern);
}
