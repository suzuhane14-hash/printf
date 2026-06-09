/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:28:49 by omito             #+#    #+#             */
/*   Updated: 2026/06/09 22:17:16 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_printf(const char *format, )//返り値は出力された文字数
{
	va_list	ap;
	int	count;//出力した文字数

	count = 0;
	va_start(ap, format);
	while (*fotmat)
	{
		if (*format == '%')//%を発見したら
		{
			init_format ;//とりま構造体リセット
			format++;//次の文字（d,s,c,など）を見て
			if (*format == 'd')
			       int n = va_arg(ap, int);
			else if (*format == 'c')
		 		char m = va_arg(ap,char);	
			else if (*format == 's')


			




