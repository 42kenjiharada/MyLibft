/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:30:18 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 14:01:55 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
メモリ領域のデータをバイト単位でコピーする ために使う。

src から dest へ n バイトをコピー
メモリが重なっている場合の動作は未定義（memmove() を使うべき）
NULL の扱いは未定義（標準 memcpy() にはチェックなし）
最適化されている場合がある（SIMD 命令など）

結論から言うと、ft_memcpy に NULL チェックは不要 です。
なぜなら、標準の memcpy() も NULL チェックをしないため、ft_memcpy も memcpy() と完全に同じ仕様にするべき だからです。

バイト単位でコピーして、余ったら１ビット単位でコピーするやり方があるけど、よくわからないので不採用にした。
*/
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
