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
#include "libft.h"

int	ft_printf(const char *format, ...)//返り値は出力された文字数,...は可変長引数ですよ〜の合図
{
	va_list ap;//可変長引数を管理する入れ物（変数）
	int	count;//出力した文字数
  t_format  fmt; //t_format型の変数fmt
  int n;
  int  c;//va_arg(ap, int)で取り出すから
  char  *s;//ポインタは8バイトなのでデフォルト引数昇格しない
  char  *tmp;//itoa用の一時変数

	count = 0;
	va_start(ap, format);//変数apに可変長引数が紐付けられる
	while (*format)
	{
		if (*format == '%')//%を発見したら
		{
			fmt = init_format();//%を見つけるたびに構造体リセット
			format++;//次の文字（d,s,c,など）を見て
			if (*format == 'd')
      {
			  n = va_arg(ap, int);//入れ物から一つint型で取り出す
        ft_putnbr_fd(n, 1);
        tmp = ft_itoa(n);//文字数カウント処理
        count += ft_strlen(tmp);
        free(tmp);//itoaはマロックしてるのを忘れない
      }
			else if (*format == 'c')
      {	
        c = va_arg(ap, int);
        ft_putchar_fd(c, 1);
        count += 1;
      }
//C言語では ... で渡された引数は自動的に型が大きい方に変換される。これをデフォルト引数昇格
  //現代の64ビットCPUは基本的に4バイトか8バイト単位で処理するのが最も効率的だから。
			else if (*format == 's')
      {
        s = va_arg(ap, char *);
        if (s == NULL)//本物は％ｓがヌルだったら(null)と出力する
          s = "(null)";
        ft_putstr_fd(s, 1);
        count += ft_strlen(s);
      }
    } 
      else//%がついていない
      {
        ft_putchar_fd(*format, 1);
        count += 1;
      }
      format++;
  }
  va_end(ap);//後片付け
  return (count);
}
