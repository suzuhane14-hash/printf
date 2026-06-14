/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:27:11 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 15:10:33 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_type(t_format *fmt, va_list *ap)//va_arg は内部で「現在何番目の引数を読んでいるか」という読み込み位置（内部のポインタやカウンタ）を更新するため、ポインタ渡し
{
  if (fmt->type == 'd' || fmt->type == 'i')
    return (print_d_i(va_arg(*ap, int), *fmt));
  else if (fmt->type == 'c')
    return (print_c(va_arg(*ap, int)));
  else if (fmt->type == 's')
    return (print_s(va_arg(*ap, char *), *fmt));
  else if (fmt->type == 'u')
    return (print_u(va_arg(*ap, unsigned int), *fmt));//%x, %X, %u は符号なしの数値を表示する仕様(man 3 printf)
  else if (fmt->type == '%')
    return (print_percent ());
  else if (fmt->type == 'x')
    return (print_x(va_arg(*ap, unsigned int), *fmt));
  else if (fmt->type == 'X')
    return (print_upper_x(va_arg(*ap, unsigned int), *fmt));
  else if (fmt->type == 'p')
    return (print_p(va_arg(*ap, void *)));//intでもcharでもどんな型でいいのでアドレスがほしいからvoid*
  return (0);
}
