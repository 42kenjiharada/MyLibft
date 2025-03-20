/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:30:39 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 14:00:13 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
文字列の長さ（終端 \0 を除いた文字数）を取得 する。

6. ft_strlen の注意点
✅ NULL の場合、標準の strlen() は segfault になる（防ぎたい場合は NULL チェック）
✅ size_t は符号なし (unsigned) なので、負の値にはならない！
✅ ヌル終端 (\0) をカウントしない！
✅ 文字列が NULL の場合は segfault する（NULL チェックを入れれば防げる）

7. ft_strlen のまとめ
✅ 文字列の長さを取得する関数！
✅ 標準ライブラリ strlen() と同じ動作！
✅ size_t を使う！負の値はない！
✅ NULL チェックを追加すると segfault を防げる！
✅ ポインタ操作 (while (*s++)) を使うと簡潔に書ける！

NULL ポインタの扱い
strlen(NULL) は未定義動作（UB）になるため、ft_strlen も特に NULL チェックをせずに UB にしておくのが標準的です。

size_t は unsigned（符号なし）整数型。 size_t を使うことで、長さが負の値にならない ので安全。
*/
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
