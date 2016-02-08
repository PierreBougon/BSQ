/*
** bsq.h for bsq in /home/bougon_p/rendu/CPE_2015_BSQ/include
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Mon Nov 30 19:14:36 2015 Pierre Bougon
** Last update Mon Dec  7 23:31:53 2015 Pierre Bougon
*/

#ifndef  BSQ_H_
# define BSQ_H_

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_fileinfo
{
  int	nb_lines;
  int	nb_col;
  char	buf[2];
  int	fd;
}		t_fileinfo;

int	my_printf(const char *, ...);
int	my_getnbr(char *);
char	**get_patern(int, t_fileinfo *);
char	**realloc_patern(t_fileinfo *, char *);
int	**create_map(t_fileinfo *, char **);
void	draw_patern(char **, t_fileinfo *);
void	draw_map(int **, t_fileinfo *);
int	max_square(int **, t_fileinfo *);
int	change_sqrmap(int **, t_fileinfo *, int);
void	draw_final_map(int **, t_fileinfo *);
int	my_strlen(char *);

#endif /* BSQ_H_ */
