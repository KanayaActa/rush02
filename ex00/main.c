/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:12:10 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 01:12:02 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	main(int ac, char **av)
{
	char	*dict;
	char	*num_str;
	t_entry	*entries;

	if (!ft_is_valid_arg(ac, av, &num_str, &dict))
	{
		print_error("Error\n");
		return (1);
	}
	if (!ft_is_valid_dict(dict))
	{
		print_error("Dict Error\n");
		return (1);
	}
	entries = ft_into_entry(dict);
	if (ft_is_zero(num_str))
		ft_find_word(entries, "0");
	if (!ft_convert_num_to_words(num_str, entries))
	{
		print_error("Dict Error\n");
		return (1);
	}
	return (0);
}
