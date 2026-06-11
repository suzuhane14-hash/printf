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

#include "ft_printf.h"

int	ft_printf(const char *format, ...)//返り値は出力された文字数,...は可変長引数ですよ〜の合図
{
	va_list	ap構造体の呼び出し方がわかっていない;
	int	count;//出力した文字数
  t_format  fmt; //t_format型の変数fmt
  int n;
  char  c;
  char  *s;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')//%を発見したら
		{
			fmt = init_format();//%を見つけるたびに構造体リセット
			format++;//次の文字（d,s,c,など）を見て
			if (*format == 'd')
			  n = va_arg(ap, int);
			else if (*format == 'c')
		 		c = va_arg(ap, int);
//C言語では ... で渡された引数は自動的に型が大きい方に変換されます。
                   //これをデフォルト引数昇格と言います。
			else if (*format == 's')
        s = va_arg(ap, int);
