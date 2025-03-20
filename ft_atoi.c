/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:34:56 by kharada           #+#    #+#             */
/*   Updated: 2025/03/19 16:57:26 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
atoi は 標準ライブラリ <stdlib.h> に含まれる関数で、
文字列を整数（int 型）に変換する関数 だよ。
8. atoi の注意点
✅ 文字列の先頭の整数部分を int に変換できる
✅ 先頭の空白は無視、数値以外の部分が出たら変換を停止
✅ 符号（+ -）にも対応
❌ オーバーフロー時の動作は未定義（安全ではない！）
❌ NULL を渡すとクラッシュする可能性がある
❌ エラー処理ができない（strtol を使うのが推奨！）

9. atoi のまとめ
✅ atoi は文字列を int に変換する関数
✅ 空白や + - を無視し、最初の数値部分を変換する
✅ atoi("42abc") → 42（途中の文字は無視される）
✅ オーバーフローを考慮するなら strtol を使うのが安全！

long	num; // ✅ `long` を使うことでオーバーフローを検出
*/

#include "libft.h"

static size_t	skip_whitespace(const char *nptr)
{
	size_t	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r' )
	{
		i++;
	}
	return (i);
}

static int	parse_sign(const char *nptr, size_t *index)
{
	int	sign;

	sign = 1;
	if (nptr[*index] == '-')
	{
		sign = -1;
		(*index)++;
	}
	else if (nptr[*index] == '+')
	{
		(*index)++;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	num;

	i = skip_whitespace(nptr);
	sign = parse_sign(nptr, &i);
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (num > (LONG_MAX - (nptr[i] - '0')) / 10)
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * num);
}
