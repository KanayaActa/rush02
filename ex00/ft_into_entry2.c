/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_into_entry2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 05:16:28 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 05:38:03 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	count_lines(char **lines)
{
	int	count;

	count = 0;
	while (lines[count])
		count++;
	return (count);
}

t_entry	*allocate_entries(int line_count)
{
	t_entry	*entries;

	entries = malloc(sizeof(t_entry) * (line_count + 1));
	if (!entries)
		return (NULL);
	return (entries);
}

int	parse_all_lines(char **lines, t_entry *entries)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		entries[i] = parse_line_to_entry(lines[i]);
		i++;
	}
	entries[i].key = NULL;
	entries[i].value = NULL;
	return (1);
}

t_entry	*ft_into_entry(char *dict)
{
	int		line_count;
	t_entry	*entries;
	char	**lines;

	if (!dict)
		return (NULL);
	lines = ft_split(dict, "\n");
	if (!lines)
		return (NULL);
	line_count = count_lines(lines);
	entries = allocate_entries(line_count);
	if (!entries)
	{
		free_split(lines);
		return (NULL);
	}
	parse_all_lines(lines, entries);
	free_split(lines);
	return (entries);
}
