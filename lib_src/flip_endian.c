/*
** flip_endian.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:02:38 2015 Guillaume Pirou
** Last update Sun Apr 12 17:02:39 2015 Guillaume Pirou
*/

char	flip_endian(char nb)
{
  int	i;
  char	res;

  res = 0;
  i = 0;
  while (i < 7)
    {
      res |= (nb & 1);
      res <<= 1;
      nb >>= 1;
      i++;
    }
  res |= (nb & 1);
  return (res);
}
