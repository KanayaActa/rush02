/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:57:24 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 00:59:08 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

char	*ft_find_word(t_entry *entries, char *search_num)
{
	int	i;

	if (!entries || !search_num)
		return (NULL);
	i = 0;
	while (entries[i].key)
	{
		if (ft_strcmp(entries[i].key, search_num) == 0)
		{
			return (ft_strdup(entries[i].value));
		}
		i++;
	}
	return (NULL);
}
