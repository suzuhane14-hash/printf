/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 01:34:42 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 01:47:11 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//printf("%d %s %c", 42, "hello", 'A');みたいに、複数の変換を連続して処理するので、一回一回構造体をリセットしたい
t_format	init_format(void)
{
	t_format	fmt;//t_format型の変数fmtを作る
//.は「この箱の中の〇〇」という意味
	fmt.minus		= 0;//fmtのminusの入れ物（変数）に0を代入
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

void  parse_flags(const char **format, t_format *fmt)//ヘルパー関数のなかでポインタを進めて、ポインタのアドレスを返したいので引数ダブルポインタ
{
  while (**format == '-' || **format == '0'
    || **format == '+' || **format == '#' || **format == ' ')
  {
    if (**format == '-')
      fmt->minus = 1;//構造体の変数fmtの中のminusというメンバに１を代入
    else if (**format == '0')
      fmt->zero = 1;
    else if (**format == '#')
      fmt->hash = 1;
    else if (**format == '+')
      fmt->plus = 1;
    else if (**format == ' ')
      fmt->space = 1;
    (*format)++;//format文字列の次の文字に進む（ダブルポインタであることを忘れない）
  } 
}

void  parse_width(const char **format, t_format *fmt)//幅を指定
{
  while (**format >= '0' && **format <= '9')
  {
    fmt->width_min = fmt->width_min * 10 + (**format - '0');//一桁ずつ読んでwidth_minを更新していくイメージ
    (*format)++;
  }
}

void  parse_precision(const char **format, t_format *fmt)//ピリオドが来たらその後の数字をprecisionに読み込む
{
  if (**format == '.')
  {
    fmt->period = 1;
    (*format)++;
    while (**format >= '0' && **format <= '9')
    {
      fmt->precision = fmt->precision * 10 + (**format - '0');
      (*format)++;
    } 
  }
}

