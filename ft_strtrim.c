/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:58:50 by kharada           #+#    #+#             */
/*   Updated: 2025/03/20 07:22:04 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
C言語には strtrim という標準関数はない
文字列の前後の特定の文字（空白・改行・タブなど）を削除する関数

1. strtrim の考え方
strtrim は、次の処理をする：

先頭 (start) の空白文字をスキップ
末尾 (end) の空白文字をスキップ
必要な部分だけを malloc でコピーして新しい文字列を返す
7. strtrim の注意点
✅ C言語には strtrim はないので、自作が必要！
✅ malloc を使って新しいメモリを確保するので free() が必要！
✅ isspace() を使えば空白（スペース・タブ・改行）を削除できる！
✅ trim_chars を渡せば、特定の文字を削除できる！
❌ NULL を渡すと segfault（セグフォ）するので NULL チェックが必要！

8. strtrim のまとめ
✅ C言語には strtrim はないので、malloc を使って自作する！
✅ isspace() を使えば空白トリム、trim_chars を渡せば好きな文字を削除できる！
✅ malloc したメモリは free() しないとリークの原因になる！
✅ JSON や HTML などの前後の不要な記号を削除するのにも便利！
*/
#include "libft.h"

static const char	*begin_point(char const *s1, char const *set)
{
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	return (s1);
}

static const char	*end_point(char const *s1, char const *set)
{
	const char	*end;

	end = s1 + ft_strlen(s1);
	while (end > s1 && ft_strchr(set, *(end -1)))
		end--;
	return (end);
}

static char	*trim_alloc(const char *begin, const char *end)
{
	size_t	dest_len;
	char	*dest;

	if (begin >= end)
		return (ft_strdup(""));
	dest_len = end - begin;
	dest = malloc(dest_len + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, begin, dest_len);
	dest[dest_len] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*begin;
	const char	*end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	begin = begin_point(s1, set);
	end = end_point(s1, set);
	return (trim_alloc(begin, end));
}
