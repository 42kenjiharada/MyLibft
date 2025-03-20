/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:31:44 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 16:54:26 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
calloc は ヒープメモリを確保し、ゼロで初期化する関数 です。
#include <stdlib.h>
void *calloc(size_t nmemb, size_t size);
📌 calloc の動作
メモリを nmemb * size バイト分確保
すべてのバイトを 0 に初期化
成功すればポインタを返し、失敗すれば NULL を返す
オーバーフロー (nmemb * size が SIZE_MAX を超える場合) を検出して NULL を返す

calloc は、ヒープメモリを確保し、すべてのバイトをゼロで初期化する C 標準ライブラリ関数です。
#include <stdlib.h>
void *calloc(size_t count, size_t size);

引数
引数	説明
count	確保する要素の数
size	各要素のバイト数
確保されるメモリサイズ = count * size
すべてのバイトが 0 に初期化される（malloc とは異なる）
📌 calloc の戻り値
成功 → 確保されたメモリのポインタを返す
失敗 → NULL を返す
📌 calloc の動作
malloc(count * size) を呼び出してメモリを確保
memset(ptr, 0, count * size) を実行して ゼロ初期化
確保されたメモリのポインタを返す

✅ nmemb == 0 または size == 0 の場合、malloc(0) を呼ぶ
✅ nmemb * size > SIZE_MAX のオーバーフローを検出し NULL を返す
✅ malloc(m_size) でメモリを確保し、NULL の場合はエラー処理
✅ memset(mem, 0, m_size) でゼロ初期化する

malloc(0) の動作は実装依存
標準 C 仕様 では malloc(0) の動作は 未定義ではなく、実装依存 とされています。
一般的な挙動は 以下の2つのいずれか：
NULL を返す
有効なポインタを返すが、使用してはいけない（dereference は未定義動作）
malloc(0) が有効なポインタを返す場合
一部の malloc 実装では malloc(0) でも 有効なポインタを返す ことがあります。
ただし、そのポインタを参照 (*ptr) すると未定義動作。
*/
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	m_size;
	char	*mem;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	m_size = nmemb * size;
	mem = malloc(m_size);
	if (mem == NULL)
		return (NULL);
	memset(mem, 0, m_size);
	return (mem);
}
