/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omito <omito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:07:22 by omito             #+#    #+#             */
/*   Updated: 2026/06/09 14:50:37 by omito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	print_ints(int count, ...)
{
	va_list ap;
	va_start(ap, count); //countの次から読む準備（栞を挟むイメージ）
	
	int i;
	i = 0;
	while (i < count)
	{
		int n = va_arg(ap, int); //指定した型（int型）で一つ取り出す
		printf("%d\n", n);
		i++;
	}
	va_end(ap);//可変長引数を使ったら片付ける
		   //環境によっては va_start が動的にメモリを確保することがあります。
		   //その場合 va_end を呼ばないとメモリリークします。
		   //libftで散々やった free を忘れるのと同じ問題です。
}

int main(void)
{
	print_ints(3, 10, 20, 30);
}
