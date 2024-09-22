/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:06:40 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 11:51:00 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	ft_handle_zero(t_entry *entries, char *num_str)
{
	char	*word;

	if (ft_is_zero(num_str))
	{
		word = ft_find_word(entries, "0");
		if (word)
		{
			ft_putstr(word);
			ft_putstr("\n");
			free(word);
			return (1);
		}
	}
	return (0);
}

int	ft_is_zero(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
