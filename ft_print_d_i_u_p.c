/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i_u_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:27:44 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 11:55:21 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_d_i(int n)
{
  ft_putnbr_fd(n, 1);
  return (ft_int_len(n));
}

int print_u(unsigned int u)
{
  ft_put_unsignedint_fd(u, 1);//文字数カウント処理
  return (ft_unsignedint_len(u));
}

int print_p(void *ptr)
{
  if (ptr == NULL)//ポインタのヌルはガード必須
  {
    write(1, "(nil)", 5);//本物はポインタがヌルのとき(nil)と出力する（linux環境）
    return (5);
  }
  else
  {
    write(1, "0x", 2);//本物の％pの出力形式的に0xを冒頭につける（数値の表記方法を区別するために接頭辞）ex:二進数は「0b」
    ft_puthex_ptr_fd((unsigned long)ptr, 1); //64bit環境では8バイトなので8バイトの型であるlong型にキャスト。void *(ポインタ)のままでは計算処理できないので、数値として扱える型にキャスト 
    return (2 +ft_ptr_hexlen((unsigned long)ptr));
  } 
}
