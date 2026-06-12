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
  //t_format  fmt; //t_format型の変数fmt
  int n;
  int  c;//va_arg(ap, int)で取り出すから
  char  *s;//ポインタは8バイトなのでデフォルト引数昇格しない
  unsigned int  u;
  char  *tmp;//itoa用の一時変数

	count = 0;
	va_start(ap, format);//変数apに可変長引数が紐付けられる
	while (*format)
	{
		if (*format == '%')//%を発見したら
		{
			//fmt = init_format();//%を見つけるたびに構造体リセット
			format++;//次の文字（d,s,c,など）を見て
			if (*format == 'd' || *format == 'i')
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
      else if (*format == '%')
      {
        ft_putchar_fd(*format, 1);
        count += 1;
      }
      else if (*format == 'u')//符号なしの10進数
      {
        u = va_arg(ap, unsigned int);
        ft_putnbr_fd(u, 1);
        tmp = ft_itoa(u);//文字数カウント処理
        count += ft_strlen(tmp);
        free(tmp);
      }
      else if (*format == 'x')
      {
        u = va_arg(ap, unsigned int);
        ft_puthex_lowercase_fd(u, 1);
        tmp = ft_itoa(u);
        count += ft_strlen(tmp);
        free(tmp);
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

void  ft_put_unsignedint_fd(unsigned int n, int fd)//ft_putnbrのマイナス処理いらないバーション
{
  char  c;

  if (fd < 0)
    return ;
  if (n >= 10)
    ft_put_unsignedint_fd(n / 10, fd);
  c = n % 10 + '0';
  write(fd, &c, 1);
}

void  ft_puthex_lowercase_fd(unsigned int n, int fd)//unsigned intの理由…16進数をプログラミングで使う用途はメモリの中身（ビット列）を表示すること。メモリにマイナスの概念はない。
{
  char  *base;

  base = "0123456789abcdef";
  if (fd < 0)
    return ;
  if (n >= 16)
    ft_puthex_lowercase_fd(n / 16, fd);
  write(fd, &base[n % 16], 1);//16で割ったあまりが、最終的に出力したい16進数（bace）のインデックスと一致している
}

void  ft_puthex_uppercase_fd(unsigned int n, int fd)
{
  char  *base;

  base = "0123456789ABCDEF";
  if(fd < 0)
    return ;
  if (n >= 16)
    ft_puthex_uppercase_fd(n / 16, fd);
  write(fd, &base[n % 16], 1);
}

int ft_hexlen(unsigned int n)
{

}
int main(void)
{
  int len;
  int n = 123;
  len = ft_printf("mori%s\n", "nikaeru");
  ft_printf("count: %d\n", len);
  ft_printf("%c\n", 'A');
  ft_printf("%u\n", n);
  ft_printf("%%\n");
  return (0);
}
