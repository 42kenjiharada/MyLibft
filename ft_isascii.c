/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:30:08 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 12:33:26 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
与えられた文字が ASCII 文字（0～127）かどうかを判定 する関数。
コードのポイント
c が 0（ASCII: 0）～ 127（ASCII: 127） の範囲にあるかチェック
ASCII 文字なら 1 を返す
それ以外の文字なら 0 を返す（拡張ASCII・UTF-8 など）

isascii(c) は c が ASCII 文字（0～127）の場合 1 を返す
それ以外（負の値、拡張ASCII 128～255 など）は 0 を返す
isascii() は unsigned char のキャストは不要（int で動作）
*/
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
