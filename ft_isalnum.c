/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:28:55 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 12:28:10 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
引数が英数字（アルファベット A～Z, a～z または 数字 0～9）かどうかを判定 する。
A～Z, a～z, 0～9 の場合、1 を返す。それ以外の場合、0 を返す。

標準の isalnum() は、以下の条件を満たすと完全に正しく動作する：
引数 c が unsigned char の範囲 (0～255) または EOF の場合にのみ動作
負の値を受け取った場合の動作が unsigned char に変換される
EOF (-1) を渡しても segfault にならない

標準の isalnum() は c を unsigned char にキャストして処理 している。
unsigned char に変換して isalnum() と同じ動作にする
*/
#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	uc;

	if (c == EOF)
		return (0);
	uc = (unsigned char)c;
	if ((uc >= 'A' && uc <= 'Z') || (uc >= 'a' && uc <= 'z')
		|| (uc >= '0' && uc <= '9'))
		return (1);
	return (0);
}
