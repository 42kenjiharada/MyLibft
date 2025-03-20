/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 06:28:40 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 15:15:16 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
標準の strrchr の動作を正しく再現しています。具体的には、

動作仕様:

文字列 s 内で、引数 c（int 型）の値（比較時には (unsigned char)c として解釈される）が最後に現れる位置のポインタを返す。
見つからなければ NULL を返す。
もし c がヌル文字 ('\0') の場合、文字列の終端（ヌル終端の位置）のポインタを返す。
実装のポイント:

ポインタを使って文字列を順に走査し、見つかった場合に c_pointer にその位置を保存している。
ループ後、c が '\0' の場合は、ループを抜けた時点での s（つまりヌル終端の位置）を返す。
(unsigned char)c によるキャストは、符号拡張などの問題を防ぐために有用です（特に符号付き char の環境では）。
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*c_pointer;

	c_pointer = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			c_pointer = ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *) s);
	return (c_pointer);
}
