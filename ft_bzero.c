/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:27:51 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 13:23:58 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s の先頭から n バイトを 0 にする
これは、memset(s, 0, n); と同じ動作
NULL の場合の動作は未定義（通常 segfault）
一部の環境では bzero() は非推奨（memset() に置き換え推奨）
指定したメモリ領域をゼロ（\0）で埋める ために使う。
bzero は、指定したメモリ領域をゼロで埋める関数
しかし、C99 以降では非推奨
1. unsigned char * へのキャスト
((unsigned char *)s)[i] = 0;
void *s は型が不明な汎用ポインタなので、unsigned char * にキャストする必要がある。
char（1バイト単位）の配列として扱うことで、バイト単位で 0 を代入できる。
unsigned char を使う理由は、符号あり char だと
 -128 ~ 127 の範囲になり、予期しない動作を防ぐため。
■ポインタ演算で最適化
標準の bzero() は memset(s, 0, n); を使う実装が多いため、CPU の memset 命令で最適化されることがある。
ft_bzero はループ処理のため、最適化がなく bzero() より遅い可能性がある。
n の値が 0 になるまで繰り返す（n をデクリメントしながらループ）。
n が ゼロになったらループを抜ける。
*p = 0; → 現在のアドレスに 0 をセット
p++ → ポインタを1バイト分進める（次のアドレスへ）
これを n 回繰り返す ことで、メモリを 0 で埋める。
*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}
