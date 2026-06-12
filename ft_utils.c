/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 01:48:44 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 01:51:45 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  ft_put_unsignedint_fd(unsigned int n, int fd)//ft_putnbrのマイナス処理いらないバーション
{
  char  c;

  if (fd < 0)
    return ;
  if (n >= 10)
    ft_put_unsignedint_fd(n / 10, fd);
  c = n % 10 + '0';
  write(fd, &c, 1);
}

void  ft_puthex_lowercase_fd(unsigned int n, int fd)//unsigned intの理由…16進数をプログラミングで使う用途はメモリの中身（ビット列）を表示すること。メモリにマイナスの概念はない。
{
  char  *base;

  base = "0123456789abcdef";
  if (fd < 0)
    return ;
  if (n >= 16)
    ft_puthex_lowercase_fd(n / 16, fd);
  write(fd, &base[n % 16], 1);//16で割ったあまりが、最終的に出力したい16進数（bace）のインデックスと一致している
}

void  ft_puthex_uppercase_fd(unsigned int n, int fd)
{
  char  *base;

  base = "0123456789ABCDEF";
  if(fd < 0)
    return ;
  if (n >= 16)
    ft_puthex_uppercase_fd(n / 16, fd);
  write(fd, &base[n % 16], 1);
}

void  ft_puthex_ptr_fd(unsigned long n, int fd)// ft_puthex_lowercase_fdの引数をlong型に変えただけ
{
  char  *base;

  base = "0123456789abcdef";
  if (fd < 0)
    return ;
  if (n >= 16)
    ft_puthex_ptr_fd(n / 16, fd);
  write(fd, &base[n % 16], 1);
}
