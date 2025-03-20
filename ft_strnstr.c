/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 07:33:08 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 15:46:38 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strnstr は 標準ライブラリ <string.h>（BSD 系） に含まれる関数で、
指定した文字列の中から、部分文字列（サブストリング）を最大 n バイト以内で検索する関数。
7. strnstr の注意点
✅ 最大 len バイト以内で検索するので、長すぎる文字列を扱う場合に安全！
✅ 部分文字列 needle の最初の出現位置を返す
✅ needle が ""（空文字列）なら haystack を返す
❌ needle が NULL の場合は未定義動作（NULL チェックを追加すべき）
❌ haystack に NULL を渡すとクラッシュする可能性がある

8. strnstr のまとめ
✅ haystack 内で needle を最大 n バイト以内で検索する関数
✅ 最初に見つかった部分文字列のポインタを返す（なければ NULL）
✅ len を超える部分は検索しないので、バッファオーバーフローを防げる
✅ NULL チェックを忘れずに！（安全なコードを書く）

この実装は、指定した len バイト以内で needle が haystack に出現するかを正しく検索し、
出現した場合は最初の位置を、見つからなければ NULL を返すという、標準 strnstr の動作と同じです。
size_t lenと方を合わせるために、	size_t	i;　size_t	j;としている。
*/
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (i < len && (haystack[i] != '\0'))
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
