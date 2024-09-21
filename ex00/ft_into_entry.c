/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_into_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:38:37 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 01:14:56 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

t_entry	parse_line_to_entry(char *line)
{
	t_entry	entry;
	char	**sep;
	char	**words;
	char	*joined_value;

	entry.key = NULL;
	entry.value = NULL;
	sep = ft_split(line, ":");
	if (!sep || !sep[0] || !sep[1])
	{
		if (sep)
			free(sep);
		return (entry);
	}
	entry.key = ft_strdup(sep[0]);
	words = ft_split(sep[1], " ");
	if (!words)
	{
		free(sep[0]);
		free(sep);
		return (entry);
	}
	joined_value = ft_strjoin(1, words, " ");
	if (!joined_value)
	{
		// メモリリークを防ぐために解放
		for (int i = 0; words[i]; i++)
			free(words[i]);
		free(words);
		free(sep[0]);
		free(sep);
		return (entry);
	}
	entry.value = joined_value;
	// メモリの解放
	for (int i = 0; words[i]; i++)
		free(words[i]);
	free(words);
	free(sep[0]);
	free(sep);
	return (entry);
}

t_entry	*ft_into_entry(char *dict)
{
	int		i;
	t_entry	*entries;
	char	**lines;
	int		line_count;

	if (!dict)
		return (NULL);
	lines = ft_split(dict, "\n");
	if (!lines)
		return (NULL);
	for (line_count = 0; lines[line_count]; line_count++)
		;
	entries = malloc(sizeof(t_entry) * (line_count + 1));
	if (!entries)
	{
		// メモリリークを防ぐために解放
		for (int i = 0; lines[i]; i++)
			free(lines[i]);
		free(lines);
		return (NULL);
	}
	i = 0;
	while (lines[i])
	{
		entries[i] = parse_line_to_entry(lines[i]);
		// 無効なエントリはスキップ（キーと値が NULL）
		if (entries[i].key == NULL || entries[i].value == NULL)
		{
			// すでに NULL が設定されているので何もしない
		}
		i++;
	}
	entries[i].key = NULL;
	entries[i].value = NULL;
	// メモリの解放
	for (int j = 0; lines[j]; j++)
		free(lines[j]);
	free(lines);
	return (entries);
}
