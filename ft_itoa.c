/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:15:40 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 09:50:17 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
C言語には 標準の itoa 関数はない（非標準関数） けど、
整数を文字列に変換する関数を自作 できる！

1. itoa の考え方
int を char[]（C文字列）に変換
sprintf() を使えば簡単に変換できるが、自作も可能
malloc を使って動的にメモリを確保する方法もある
6. itoa の注意点
✅ C言語には itoa はないので sprintf または自作する！
✅ buffer を使うか、malloc でメモリを確保するか選ぶ！
✅ malloc 版は free() しないとメモリリークの原因になる！
✅ base は 2～36 の範囲内で指定する（10進・16進・2進など）
❌ オーバーフローやメモリ確保ミスに注意！

7. itoa のまとめ
✅ C言語には itoa はないので、自作または sprintf() を使う！
✅ バッファ渡し版（itoa(value, buffer, base)）は安全！
✅ 動的メモリ版（malloc 使用）は free() が必要！
✅ sprintf("%d", value) なら簡単に itoa の代わりになる！
*/

#include "libft.h"

static int	digit_count(long int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			count;
	long int	num;
	char		*result;

	count = digit_count(n);
	num = n;
	if (num < 0)
		num = -num;
	result = ft_calloc(count + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (num == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (n < 0)
		result[0] = '-';
	count--;
	while (num != 0)
	{
		result[count] = (num % 10 + '0');
		num = num / 10;
		count--;
	}
	return (result);
}
