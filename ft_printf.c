/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 01:38:01 by omito             #+#    #+#             */
/*   Updated: 2026/06/13 01:53:20 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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

int ft_printf(const char *format, ...)//返り値は出力された文字数,...は可変長引数ですよ〜の合図
{
	va_list ap;//可変長引数を管理する入れ物（変数）
	int	count;//出力した文字数
  t_format  fmt; //t_format型の変数fmt

	count = 0;
	va_start(ap, format);//変数apに可変長引数が紐付けられる
	while (*format)
	{
		if (*format == '%')//%を発見したら
		{
			fmt = init_format();//%を見つけるたびに構造体リセット
			format++;//次の文字（d,s,c,など）を見て
      parse_flags(&format, &fmt);//ボーナスたちの処理３連
      parse_width(&format, &fmt);
      parse_precision(&format, &fmt);
      fmt.type = *format;
      count += handle_type(&fmt, &ap);
    } 
    else //%がついていない
    {
        ft_putchar_fd(*format, 1);
        count += 1;
    }
    format++;
  }
  va_end(ap);//後片付け
  return (count);
}

  		//C言語では ... で渡された引数は自動的に型が大きい方に変換される。これをデフォルト引数昇格
  //現代の64ビットCPUは基本的に4バイトか8バイト単位で処理するのが最も効率的だから。

//int main(void)
//{
//  int len;
//  int n = 123;
//  len = ft_printf("mori%s\n", "nikaeru");
//  ft_printf("count: %d\n", len);
//  ft_printf("%c\n", 'A');
//  ft_printf("%u\n", n);
//  ft_printf("%%\n");
//  ft_printf("%p\n", &n);
//  ft_printf("%i\n", n);
//  ft_printf("%u\n", n);
//  ft_printf("%x\n", n);
//  ft_printf("%X\n", n);
//
//  return (0);
//}
