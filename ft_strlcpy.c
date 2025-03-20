/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:30:33 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 14:16:45 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strlcpy は バッファオーバーフローを防ぐための安全な文字列コピー関数 で、
最大 size - 1 文字をコピーし、必ず \0（ヌル終端）を追加する。

src から dest に 最大 size - 1 文字コピー
dest の 最後に \0 を付与する（size > 0 の場合）
NULL の場合の処理は未定義（チェックは不要）
戻り値は strlen(src)（コピーしなかった分も含めた src の長さ）

■src が NULL の場合は 0 を返す（安全対策）
dest が NULL で size > 0 の場合はクラッシュを防ぐために 0 を返す
*/
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	if (!src)
		return (0);
	if (!dest && size > 0)
		return (0);
	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (size == 0)
		return (src_size);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}
