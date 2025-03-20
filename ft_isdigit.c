/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:30:12 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 12:12:25 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isdigit の動作
引数 c が '0'〜'9' の場合 → 1 を返す
それ以外（アルファベット、記号、空白、負の値など）→ 0 を返す
引数が unsigned char の範囲外（負の値や EOF）の動作
標準の isdigit は、EOF (-1) を考慮しており、安全に動作する
isdigit(c) を呼ぶとき、c は unsigned char または EOF に変換されるべき

if (c < 0 || c > 255) // 負の値や範囲外の値を排除
✅ c < 0 の場合は即 0 を返す（EOF などの未定義動作を防ぐ）
✅ c > 255 の場合も 0 を返す（isdigit は unsigned char しか受け付けないため）
*/
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < 0 || c > 255)
		return (0);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
