/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_dict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:13:43 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 01:12:23 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	ft_is_valid_dict(char *dict)
{
	if (!dict)
		return (0);
	while (*dict)
	{
		while ('0' <= *dict && *dict <= '9')
			dict++;
		while (*dict == ' ')
			dict++;
		if (*dict != ':')
			return (0);
		dict++;
		while (*dict == ' ')
			dict++;
		if (!(*dict >= 32 && *dict < 127))
			return (0);
		while (*dict >= 32 && *dict < 127)
			dict++;
		if (*dict != '\n' && *dict != '\0')
			return (0);
		if (*dict == '\n')
			dict++;
	}
	return (1);
}
