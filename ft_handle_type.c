/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:27:11 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 11:47:57 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_type(t_format *fmt, va_list *ap)
{
  if (fmt->type == 'd' || fmt->type == 'i')
    return (print_d_i(va_arg(*ap, int), *fmt));
}
