/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_vaild_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:21:38 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 11:50:07 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	ft_is_valid_num(char *str)
{
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (0);
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}
