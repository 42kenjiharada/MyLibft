/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:30:03 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 12:17:52 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isalpha は、与えられた文字が アルファベット（A～Z, a～z） かどうかを判定する関数。
A～Z または a～z の場合、1 を返す。それ以外の場合、0 を返す。
■isalpha の標準的な動作
引数 c が A-Z または a-z の場合 → 1 を返す
それ以外（数字や記号など）→ 0 を返す
引数が unsigned char の範囲外（負の値）や EOF の場合の動作
標準の isalpha は、EOF (-1) でも問題なく動作する
isalpha(c) を呼ぶとき、c は unsigned char または EOF に変換される必要がある
✅ unsigned char にキャスト
c を unsigned char に変換してから判定することで、負の値の影響を受けない。
isalpha(-1) を呼んでも、未定義動作を防げる。
✅ EOF (-1) の対応
EOF が入力されたとき、標準の isalpha と同じ挙動（0 を返す）にする。
*/
#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc >= 'A' && uc <= 'Z')
		return (1);
	if (uc >= 'a' && uc <= 'z')
		return (1);
	return (0);
}
