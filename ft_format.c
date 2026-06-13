/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:58:38 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 11:28:18 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  print_spaces(int n)//幅を埋めるために使用
{
    while (n > 0)
    {
        write(1, " ", 1);
        n--;
    }
}

void  print_zeros(int n)//幅を0で埋めるために使用
{
    while (n > 0)
    {
        write(1, "0", 1);
        n--;
    }
}

int print_format(char *str, t_format fmt)//文字列 str とフォーマット情報 fmt を受け取って、幅、揃えを適用して出力
{
  int len;
  int width;

  len = (int)ft_strlen(str);
  width = fmt.width_min - len;//実際に埋める幅を計算
  if (fmt.minus == 1)//左揃え
  {
    ft_putstr_fd(str, 1);
    print_spaces(width);
  }
  else if (fmt.zero == 1)//0梅
  {
    print_zeros(width);
    ft_putstr_fd(str, 1);
  }
  else//右揃え（デフォルト）
  {
    print_spaces(width);
    ft_putstr_fd(str, 1);
  }
  if (fmt.width_min > len)//返したいのは実際に出力された文字数
    return (fmt.width_min);
  else
    return (len);
}
