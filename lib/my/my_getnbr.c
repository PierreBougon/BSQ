/*
** my_getnbr.c for getnbr in /home/bougon_p/rendu
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Fri Oct  9 14:56:57 2015 Pierre Bougon
** Last update Sun Nov 29 23:19:57 2015 Pierre Bougon
*/

int	str_to_int(int h, char *str, int counter, int i)
{
  int	stock;

  i = i - counter;
  stock = 0;
  while (h > 1)
    {
      stock = stock + ((str[i] - 48) * h);
      h = h / 10;
      i = i + 1;
    }
  return (stock / 10);
}

int	my_getnbr(char *str)
{
  int	i;
  int	h;
  int	counter;
  int 	stock;
  int	multi;

  if (!str)
    return (1);
  multi = 1;
  counter = 0;
  i = 0;
  h = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      multi = ((str[i] == '-') ? multi * -1 : multi);
      i = i + 1;
    }
  counter = 0;
  h = 1;
  while (str[i] >= 48 && str[i] <= 57)
    {
      i = i + 1;
      counter = counter + 1;
      h = h * 10;
    }
  stock = str_to_int(h, str, counter, i);
  return (stock * multi);
}
