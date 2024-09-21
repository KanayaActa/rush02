/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:51:36 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 01:00:37 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	print_error(const char *message)
{
	if (!message)
		return ;
	while (*message)
		write(2, message++, 1);
}

void	ft_putstr(const char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
