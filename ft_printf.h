/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:00:30 by omito             #+#    #+#             */
/*   Updated: 2026/06/09 18:10:58 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT-PRINTF_H

#include <stdarg.h>
#include <unistd.h>

typedef struct s_format
{
    int minus;    // -
    int zero;     // 0
    int hash;     // #
    int plus;     // +
    int space;    //
    int width_min;    // 最小フィールド幅
    int precision; // 精度
    char type;    // c, s, d, i, u, x, X, p, %
} t_format;
//printf("%d %s %c", 42, "hello", 'A');みたいに、複数の変換を連続して処理するので、一回一回構造体をリセットしたい

t_format	init_format(void)
{
	t_format	fmt;//t_format型の変数fmtを作る
//.は「この箱の中の〇〇」という意味
	fmt.minus		= 0;//fmtのminusの入れ物に0を入れる
	fmt.zero		= 0;
	fmt.hash		= 0;
	fmt.plus		= 0;
	fmt.space		= 0;
	fmt.width_min	= 0;
	fmt.precision	= 0;
	fmt.period		= 0;
	fmt.type		= '\0';
	return (fmt);
}
