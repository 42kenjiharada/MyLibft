/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:30:21 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 14:36:13 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
メモリ領域が重なる場合でも安全にコピーできるメモリ操作関数
dest ：コピー先のメモリ領域（ポインタ）
src ：コピー元のメモリ領域（ポインタ）
num ：コピーするバイト数
戻り値：コピー先 dest のポインタ

memmove() の標準仕様
メモリが重なっていても正しくコピーする
memcpy() は重なった場合に未定義動作になるが、memmove() は安全
NULL を渡したときの動作は未定義（標準 memmove() は NULL チェックをしない）
*/
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	if ((unsigned char *)src >= (unsigned char *)dest + n)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		}
	}
	return (dest);
}
