/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 06:44:33 by kharada           #+#    #+#             */
/*   Updated: 2025/03/20 07:01:31 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strchr は 標準ライブラリ <string.h> に含まれる関数で、
文字列の中から指定した文字を検索し、最初に見つかった位置を返す関数
✅ c が見つかると、その位置のポインタを返す
✅ 見つからない場合は NULL を返す（NULL チェックを忘れない！）
✅ '\0'（ヌル終端文字）も検索できる
❌ 見つかったポインタは const 扱いしないと segfault の原因になる！

char *ft_strchr(const char *s, int c);
s 内に c が含まれているかを検索し、最初に見つかった位置のポインタを返す。
見つからなかった場合は NULL を返す。
c は char だが int 型で渡される（C標準の仕様）。
s の \0 終端も検索対象に含まれる。
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
