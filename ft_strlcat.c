/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 06:43:24 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 14:37:06 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strlcat は 安全に文字列を連結（concat）する関数 で、
バッファオーバーフローを防ぎながら dest に src を追加する。
✅ strlcpy と同様に、\0（ヌル終端）を必ず追加する！
✅ dest のサイズを考慮しながら連結するので、安全！

dest と srcのサイズを計算する。
	while (dest_size < size && dest[dest_size] != '\0')
		dest_size++;　バッファサイズ size を超えないようにしている
		
	while (src[src_size] != '\0')
		src_size++;
*/
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	if (!src)
		return (0);
	if (!dest && size > 0)
		return (0);
	i = 0;
	dest_size = 0;
	src_size = 0;
	while (dest_size < size && dest[dest_size] != '\0')
		dest_size++;
	while (src[src_size] != '\0')
		src_size++;
	if (size <= dest_size)
		return (size + src_size);
	while ((dest_size + i < size - 1) && (src[i] != '\0'))
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}
