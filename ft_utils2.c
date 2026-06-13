/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 01:56:01 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 12:26:39 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_int_len(int n)
{
  int len_counter;
  long  nbr;

  len_counter = 0;
  if (n == 0)
    return (1);
  nbr = n;
  if (nbr < 0)
  {
    len_counter++;//-分カウント
    nbr = -nbr;
  }
  while (nbr > 0)
  {
    nbr = nbr / 10;
    len_counter++;
  }
  return (len_counter);
}

int ft_unsignedint_len(unsigned int n)
{
  int len_counter;

  len_counter = 0;
  if (n == 0)
    return (1);
  while (n > 0)
  {
    n = n / 10;
    len_counter++;
  }
  return (len_counter);
}

int ft_hexlen(unsigned int n)//itoaは10で割りながら桁数を調べているため、16進数用の桁数え関数
{
  int len_counter;

  len_counter = 0;
  if (n == 0)
    return (1);
  while (n > 0)
  {
    n = n / 16;
    len_counter++;
  }
  return (len_counter);
}

int ft_ptr_hexlen(unsigned long n)//long型の引数に変えただけ
{
  int len_counter;

  len_counter = 0;
  if (n == 0)
    return (1);
  while (n > 0)
  {
    n = n / 16;
    len_counter++;
  }
  return (len_counter);
}
