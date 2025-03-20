/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:33:07 by kharada           #+#    #+#             */
/*   Updated: 2025/03/20 00:25:33 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strdup は、指定された文字列を動的メモリ（ヒープ領域）にコピーし、その ポインタを返す C 標準ライブラリ関数です。
#include <string.h>
char *strdup(const char *s);
📌 strdup の動作
引数 s の長さ（strlen(s)）を取得
malloc で s と同じ長さ + 1 ('\0' 分) のメモリを確保
memcpy または strcpy で s を新しいメモリにコピー
新しいメモリのポインタを返す
確保できなかった場合は NULL を返す

src == NULL の場合
標準 strdup(NULL) は未定義動作（UB）
ft_strdup(NULL) は NULL を返す
標準の strdup と完全に一致させるなら、NULL チェックを削除すべき

strdup の動作
引数 s の長さを取得 (strlen(s))
malloc(strlen(s) + 1) で新しいメモリを確保
memcpy または strcpy で s をコピー
コピーしたメモリのポインタを返す
メモリ確保に失敗した場合は NULL を返す
s == NULL の場合の動作は未定義（UB）！
標準ライブラリの strdup は、引数として NULL を渡すと未定義動作になります。
未定義動作（UB）の具体的な問題点
プログラムがクラッシュする（セグメンテーションフォルト, Segmentation Fault）
ランダムな動作をする（異常なメモリアクセス）
動作が環境やコンパイラによって変わる
予測不能なバグが発生する
*/
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	if (src == NULL)
		return (NULL);
	i = ft_strlen(src);
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	memcpy(dest, src, i);
	dest[i] = '\0';
	return (dest);
}
