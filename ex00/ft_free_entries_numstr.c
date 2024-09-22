/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_entries_numstr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:45:47 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 19:15:46 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	ft_free_entries_numstr(t_entry *entries, char *num_str, int ac)
{
	int	i;

	i = 0;
	if (!entries)
		return ;
	while (entries[i].key || entries[i].value)
	{
		if (entries[i].key)
			free(entries[i].key);
		if (entries[i].value)
			free(entries[i].value);
		i++;
	}
	free(entries);
	if (ac == 1)
		free(*num_str);
}
