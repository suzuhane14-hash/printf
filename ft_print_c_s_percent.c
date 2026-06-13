/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 02:14:05 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 10:16:42 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int print_c(int c)//var_argで取り出したchar１文字を出力して、出力した文字数をリターン
{
  ft_putchar_fd(c, 1);
  return (1);
}

int print_s(char *s)
{
  if (s == NULL)//本物は％ｓがヌルだったら(null)と出力する
  s = "(null)";
  ft_putstr_fd(s, 1);
  return (ft_strlen(s));
}

int print_percent(void)
{
  write(1, "%", 1);
  return (1);
}
