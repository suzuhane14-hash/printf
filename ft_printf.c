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
  void  *ptr;

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
      else if (*format == 'x')//16進数（小文字）で数値出力
      {
        u = va_arg(ap, unsigned int);
        ft_puthex_lowercase_fd(u, 1);
        count += ft_hexlen(u);
      }

      else if (*format == 'X')//16進数（大文字）で数値出力
      {
        u = va_arg(ap, unsigned int);
        ft_puthex_uppercase_fd(u, 1);
        count += ft_hexlen(u);
      }
      else if (*format == 'p')//変数がメモリのどこにあるか（アドレス）を16進数で出力
      {
        ptr = va_arg(ap, void *);//intでもcharでもどんな型でいいのでアドレスがほしいからvoid*
        write(1, "0x", 2);//本物の％pの出力形式的に0xを冒頭につける（数値の表記方法を区別するために接頭辞）ex:二進数は「0b」
        ft_puthex_ptr_fd((unsigned long)ptr, 1); //64bit環境では8バイトなので8バイトの型であるlong型にキャスト。void *(ポインタ)のままでは計算処理できないので、数値として扱える型にキャスト 
        count += 2 +ft_ptr_hexlen((unsigned long)ptr);
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

void  ft_puthex_ptr_fd(unsigned long n, int fd)// ft_puthex_lowercase_fdの引数をlong型に変えただけ
{
  char  *base;

  base = "0123456789abcdef";
  if (fd < 0)
    return ;
  if (n >= 16)
    ft_puthex_ptr_fd(n / 16, fd);
  write(fd, &base[n % 16], 1);
}

int ft_hexlen(unsigned int n)//itoaは10で割りながら桁数を調べているため、16進数用の桁数え関数
{
  int len_counter;

  len_counter = 0;
  if (n == 0)
    return (1);
  while (n > 0)
  {
    n = n / 16;
    len_counter++;
  }
  return (len_counter);
}

int ft_ptr_hexlen(unsigned long n)//long型の引数に変えただけ
{
  int len_counter;

  len_counter = 0;
  if (n == 0)
    return (1);
  while (n > 0)
  {
    n = n / 16;
    len_counter++;
  }
  return (len_counter);
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
