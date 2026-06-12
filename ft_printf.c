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

int	ft_printf(const char *format, ...)//返り値は出力された文字数,...は可変長引数ですよ〜の合図
{
	va_list ap;//可変長引数を管理する入れ物（変数）
	int	count;//出力した文字数
  t_format  fmt; //t_format型の変数fmt
  int n;
  int  c;//va_arg(ap, int)で取り出すから
  char  *s;//ポインタは8バイトなのでデフォルト引数昇格しない
  unsigned int  u;
  char  *tmp;//itoa用の一時変数
  void  *ptr;

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
      fmt.type = *format;// fmt->type = *formatの書き方はfmtがポインタ型(t_format *)のとき使う。今回はt_format型の変数のためこの書き方
			if (fmt.type == 'd' || fmt.type == 'i')
      {
			  n = va_arg(ap, int);//入れ物から一つint型で取り出す
        ft_putnbr_fd(n, 1);
        count += ft_int_strlen(n);
      }
			else if (fmt.type == 'c')
      {	
        c = va_arg(ap, int);
        ft_putchar_fd(c, 1);
        count += 1;
      }
//C言語では ... で渡された引数は自動的に型が大きい方に変換される。これをデフォルト引数昇格
  //現代の64ビットCPUは基本的に4バイトか8バイト単位で処理するのが最も効率的だから。
			else if (fmt.type == 's')
      {
        s = va_arg(ap, char *);
        if (s == NULL)//本物は％ｓがヌルだったら(null)と出力する
          s = "(null)";
        ft_putstr_fd(s, 1);
        count += ft_strlen(s);
      }
      else if (fmt.type == '%')
      {
        ft_putchar_fd(*format, 1);
        count += 1;
      }
      else if (fmt.type == 'u')//符号なしの10進数
      {
        u = va_arg(ap, unsigned int);
        ft_put_unsignedint_fd(u,1);//文字数カウント処理
        count += ft_unsignedint_strlen(u);
      }
      else if (fmt.type == 'x')//16進数（小文字）で数値出力
      {
        u = va_arg(ap, unsigned int);
        ft_puthex_lowercase_fd(u, 1);
        count += ft_hexlen(u);
      }

      else if (fmt.type == 'X')//16進数（大文字）で数値出力
      {
        u = va_arg(ap, unsigned int);
        ft_puthex_uppercase_fd(u, 1);
        count += ft_hexlen(u);
      }
      else if (fmt.type == 'p')//変数がメモリのどこにあるか（アドレス）を16進数で出力
      {
        ptr = va_arg(ap, void *);//intでもcharでもどんな型でいいのでアドレスがほしいからvoid*
        if (ptr == NULL)//ポインタのヌルはガード必須
        {
          write(1, "(nil)", 5);//本物はポインタがヌルのとき(nil)と出力する（linux環境）
          count += 5;
        }
        else
        {
          write(1, "0x", 2);//本物の％pの出力形式的に0xを冒頭につける（数値の表記方法を区別するために接頭辞）ex:二進数は「0b」
          ft_puthex_ptr_fd((unsigned long)ptr, 1); //64bit環境では8バイトなので8バイトの型であるlong型にキャスト。void *(ポインタ)のままでは計算処理できないので、数値として扱える型にキャスト 
          count += 2 +ft_ptr_hexlen((unsigned long)ptr);
        } 
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
