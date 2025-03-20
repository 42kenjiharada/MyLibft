/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:30:25 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 12:47:54 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
メモリの指定範囲を特定の値で埋めるために使う。
引数
s : メモリ領域の先頭アドレス（void*）
c : 設定する値（int だが、unsigned char にキャストされる）
n : 設定するバイト数（size_t）
戻り値
s の値（元のメモリのポインタ）をそのまま返す。

s の先頭から n バイトを c（unsigned char にキャスト）で埋める
メモリの先頭アドレス s を返す
NULL の場合の動作は未定義（通常 segfault する）
パフォーマンスのために CPU の memset 命令を使う場合がある（最適化あり）→今回はやっていない。

2. なぜ c は unsigned char にキャストされるのか？
(1) char 型に適用されるから
memset() は void *s のメモリ領域に c の値を n バイト分セット する関数。
しかし、Cでは char 型のメモリ操作は unsigned char として扱うのが基本。
つまり、c の型は int でも、実際にメモリに書き込まれるのは 1バイト単位の unsigned char になる。
*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) s)[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
