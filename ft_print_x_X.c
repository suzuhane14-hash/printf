/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:10:24 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 12:20:47 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_x(unsigned int u, t_format fmt)
{
  char  *str;
  int len;

  str = ft_xtoa(u, "0123456789abcdef");//数値から文字列変換
  len = print_format(str, fmt);//文字列を幅と揃えを適応して出力
  free(str);
  return (len);//実際出力した文字数を返す
}

int print_upper_x(unsigned int u, t_format fmt)
{
  char  *str;
  int len;

  str = ft_xtoa(u, "0123456789ABCDEF");//数値から文字列変換
  len = print_format(str, fmt);//文字列を幅と揃えを適応して出力
  free(str);
  return (len);//実際出力した文字数を返す
}
