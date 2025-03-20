/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 07:33:21 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 15:39:38 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memcmp は 標準ライブラリ <string.h> に含まれる関数で、
2つのメモリ領域をバイト単位で比較する関数 だよ。
7. memchr の注意点
✅ バイナリデータ（\0 を含むデータ）も検索できる
✅ 戻り値は value を指すポインタ（NULL の可能性あり）
✅ NULL 終端 \0 を考慮しないので、strchr とは異なる
❌ 見つからない場合は NULL なので、NULL チェックを忘れない！

8. memchr のまとめ
✅ メモリ領域の中から特定のバイト値を検索する関数
✅ NULL 終端 \0 を考慮しないので、バイナリデータにも使える
✅ 戻り値は見つかったバイトのポインタ、見つからないと NULL
✅ バイナリ検索、データ解析、文字列の一部検索などに便利！
❌ NULL チェックを忘れるとバグる可能性がある

memcmp の仕様
#include <string.h>
int memcmp(const void *s1, const void *s2, size_t n);
s1 と s2 の先頭 n バイトを比較する。
違いが見つかった場合： 最初に異なるバイトの差（(unsigned char)s1[i] - (unsigned char)s2[i]）を返す。
s1 と s2 が n バイト完全に一致する場合： 0 を返す。
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
