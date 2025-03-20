/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:33:44 by kharada           #+#    #+#             */
/*   Updated: 2025/03/20 01:48:11 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
C言語には 標準の strjoin 関数は存在しない けど、
2つの文字列を結合（連結）する関数を自作 できる！

1. strjoin の考え方
C言語では、文字列は char 配列（またはポインタ） なので、
文字列を結合するには新しいメモリを確保 (malloc) してコピーする 必要がある。
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
*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (s1 == NULL)
	{
		dest = ft_strdup(s2);
		return (dest);
	}
	if (s2 == NULL)
	{
		dest = ft_strdup(s1);
		return (dest);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcpy(dest + s1_len, s2, s2_len + 1);
	return (dest);
}
