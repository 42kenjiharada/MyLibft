/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:36:13 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 09:52:39 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
C言語には 標準の strmapi 関数は存在しない けど、
文字列の各文字に対して関数を適用し、新しい文字列を作成する関数 を自作できる！

1. strmapi の考え方
strmapi の目的は：

元の文字列の各文字に関数を適用する
新しい文字列を malloc で確保して返す
元の文字列は変更しない（イミュータブル）

6. strmapi の注意点
✅ C言語には strmapi はないので malloc を使って自作する！
✅ 関数ポインタ char (*f)(unsigned int, char) を適用！
✅ 新しいメモリを確保するので free() が必要！
✅ NULL チェックをして安全に処理！
❌ オリジナルの文字列は変更しない（新しい文字列を返す）

7. strmapi のまとめ
✅ strmapi は、各文字に関数を適用し、新しい文字列を作成する！
✅ 文字列を変更せず、新しい malloc メモリに結果を格納！
✅ free() しないとメモリリークの原因になる！
✅ 大文字変換・インデックス操作・文字変換などに活用可能！
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
	{
		result = malloc(sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
