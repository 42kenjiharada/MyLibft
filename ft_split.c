/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharada <kharada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:52 by kharada           #+#    #+#             */
/*   Updated: 2025/03/20 07:44:00 by kharada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
C言語には 標準の split 関数はない けど、
特定の区切り文字（デリミタ）で文字列を分割する関数を自作 できる！

1. split の考え方
元の文字列の中に、区切り文字（デリミタ）がいくつあるか数える
必要な個数のメモリを確保 (malloc) する
デリミタごとに文字列をコピーして、新しい配列に格納する
最後に NULL 終端を追加する（文字列配列の終わりを示す）

7. split の注意点
✅ C言語には split はないので malloc を使って自作する！
✅ 区切り文字（デリミタ）を自由に指定できる！
✅ malloc したメモリは free() しないとリークする！
✅ NULL チェックをして、安全なコードを書く！

8. split のまとめ
✅ split を作れば、C言語でも簡単に文字列を分割できる！
✅ 複数のデリミタ対応で、より柔軟に使える！
✅ malloc で確保したメモリは free() を忘れずに！

char **ft_split(char const *s, char c);
パラメータ
s : 分割対象の文字列
c : 区切り文字（char 型）
返り値
char** : 分割された文字列の配列（NULL 終端されている）
失敗した場合（malloc エラーなど）は NULL を返す。
メモリ管理
ft_split が返す配列は malloc で確保されるので、
使い終わったら free() で解放する必要がある。
*/

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	count; 
	int	trigger;

	count = 0;
	trigger = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int finish)
{
	char	*word;
	int		i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	free_split(char **split, size_t j)
{
	size_t i = 0;
	while (i < j)
		free(split[i++]);
	free(split);
}

static int	fill_split(char const *s, char c, char **split)
{
	size_t i = 0, j = 0, len = ft_strlen(s);
	int index = -1;
	while (i < len)
	{
		if (s[i] != c && index < 0)
			index = i;
		else if (s[i] == c && index >= 0)
		{
			split[j] = word_dup(s, index, i);
			if (!split[j])
				return (free_split(split, j), 0);
			j++;
			index = -1;
		}
		i++;
	}
	if (index >= 0)
	{
		if (!(split[j] = word_dup(s, index, i)))
			return (free_split(split, j), 0);
		j++;
	}
	split[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char **split;
	if (!s)
		return (NULL);
	split = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!fill_split(s, c, split))
		return (NULL);
	return (split);
}
