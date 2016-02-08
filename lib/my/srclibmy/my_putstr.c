/*
** my_putstr.c for putstring in /home/bougon_p/rendu/Piscine_C_J04
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Thu Oct  1 13:58:05 2015 Pierre Bougon
** Last update Thu Oct  1 23:41:28 2015 Pierre Bougon
*/

int	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}
