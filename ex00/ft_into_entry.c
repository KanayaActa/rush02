/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_into_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:38:37 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 11:16:26 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "utils.h"
#include <stdlib.h>

char	**split_line(char *line)
{
	char	**sep;

	sep = ft_split(line, ":");
	return (sep);
}

char	*process_key(char **sep)
{
	char	*key;

	key = ft_strdup(sep[0]);
	return (key);
}

char	*process_value(char **sep)
{
	char	**words;
	char	*joined_value;

	words = ft_split(sep[1], " ");
	if (!words)
		return (NULL);
	joined_value = ft_strjoin(count_size(words), words, " ");
	if (!joined_value)
	{
		free_split(words);
		return (NULL);
	}
	free_split(words);
	return (joined_value);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_entry	parse_line_to_entry(char *line)
{
	t_entry	entry;
	char	**sep;

	entry.key = NULL;
	entry.value = NULL;
	sep = split_line(line);
	if (!sep || !sep[0] || !sep[1])
	{
		free_split(sep);
		return (entry);
	}
	entry.key = process_key(sep);
	entry.value = process_value(sep);
	free_split(sep);
	return (entry);
}
