/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:10:24 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 10:41:42 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_x(unsigned int u)
{
  ft_puthex_lowercase_fd(u, 1);
  return (ft_hexlen(u));
}
int print_upper_x(unsigned int u)
{
  ft_puthex_uppercase_fd(u, 1);
  return (ft_hexlen(u));
}
