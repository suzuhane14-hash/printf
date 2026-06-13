/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 01:48:44 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 12:26:08 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_utoa(unsigned int n)
{
    char    *str;
    int     len;

    len = ft_unsignedint_len(n);
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n == 0)
        str[0] = '0';
    while (n > 0)
    {
        str[--len] = n % 10 + '0';//割って末尾の桁の数字を取り出してcharになおす
        n = n / 10;
    }
    return (str);
}

char    *ft_xtoa(unsigned int n, char *base)//１６進数を文字列に変換
{
    char    *str;
    int     len;

    len = ft_hexlen(n);
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n == 0)
        str[0] = '0';
    while (n > 0)
    {
        str[--len] = base[n % 16];//16で割ったあまりが、最終的に出力したい16進数（bace）のインデックスと一致している
        n /= 16;
    }
    return (str);
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
