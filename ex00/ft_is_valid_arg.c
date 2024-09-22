/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:23:13 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 14:12:46 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	ft_is_valid_arg(int ac, char **av, char **num_str, char **dict)
{
	if (ac == 1 || ac == 2)
	{
		*dict = ft_read_dict("numbers.dict");
		if (*dict == NULL)
			return (0);
		if (ac == 1)
			*num_str = ft_stdin();
		if (ac == 2)
			*num_str = av[1];
		if (*num_str == NULL)
			return (0);
	}
	else if (ac == 3)
	{
		*dict = ft_read_dict(av[1]);
		if (*dict == NULL)
			return (0);
		*num_str = av[2];
	}
	else
		return (0);
	if (!ft_is_valid_num(*num_str))
		return (0);
	return (1);
}
