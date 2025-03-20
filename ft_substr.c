/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:58 by kharada           #+#    #+#             */
/*   Updated: 2025/03/20 01:18:10 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
C言語には substr という標準関数はないけど、
部分文字列（substring）を取得する関数を自作 することができる！
ここでは、C言語で 文字列の一部を抜き出す方法（substring） を解説するよ。
6. substr の注意点
✅ C言語には標準の substr はないので、自作が必要
✅ malloc でメモリを確保するので、使用後に free() する必要がある
✅ start が src の長さ以上なら空文字列を返す
✅ len が src の長さを超えないように調整

7. まとめ
✅ C言語には substr はないので malloc を使って自作する！
✅ memcpy や strncpy を使い、安全に部分文字列を取得する
✅ 取得後は free() しないとメモリリークの原因になる
✅ strstr と組み合わせると、部分文字列の検索や取得ができる！

substr の標準的な仕様
🔹 substr の動作
１）src の長さを取得 (ft_strlen(src))
２）start >= src_len の場合は空文字列を返す
３）start + len > src_len の場合は、len を src_len - start に調整
４）malloc(len + 1) でメモリを確保
５）ft_strlcpy(dst, src + start, len + 1) で部分文字列をコピー
６）確保に失敗したら NULL を返す

substrの機能について
部分文字列（substring）とは
一つの文字列から、特定の開始位置から一定の長さだけを切り出した文字列のことです。
多くの高水準言語（例えば、Pythonのstr[start:end]やJavaScriptの
substringメソッドなど）では、部分文字列を容易に取得できる関数やメソッドが
用意されていますが、C言語には標準では存在しません。

C言語でのsubstrの必要性
C言語では、文字列操作において手動でポインタ操作やメモリ管理を行う必要があるため、
こうした部分文字列を取り出すための関数（例：ft_substr）を
ライブラリとして実装することがよく行われます。
この実装は、与えられた文字列の指定された位置から安全に部分文字列を抽出し、
動的メモリ確保を行い、ヌル終端も保証しているため、実用的かつ一般的な実装といえます。

 substr（部分文字列）とは？
🔹 substrの一般的な機能
「部分文字列（substring）」とは、文字列の一部を抽出する機能のこと。
例えば、"Hello, World!" から "World" だけを取り出したいとき、
C言語には標準の関数がないので、自前でft_substrのような関数を作る必要がある。
*/

#include "libft.h"

char	*ft_substr(char const *src, size_t start, size_t len)
{
	size_t	src_len;
	char	*dst;

	if (src == NULL)
		return (ft_strdup(""));
	src_len = ft_strlen(src);
	if (start >= src_len)
		return (ft_strdup(""));
	if (len > src_len - start)
		len = src_len - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, (src + start), len + 1);
	return (dst);
}
