/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:12:10 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 19:24:42 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	free_numstr_dict(char *dict, char *num_str)
{
	free(dict);
	free(num_str);
}

int	main(int ac, char **av)
{
	char	*dict;
	char	*num_str;
	t_entry	*entries;

	if (!ft_is_valid_arg(ac, av, &num_str, &dict))
	{
		free_numstr_dict(dict, num_str);
		print_error("Error\n");
		return (1);
	}
	if (!ft_is_valid_dict(dict))
	{
		free_numstr_dict(dict, num_str);
		print_error("Dict Error\n");
		return (1);
	}
	entries = ft_into_entry(dict);
	if (ft_handle_zero(entries, num_str))
	{
		ft_free_entries(entries);
		return (0);
	}
	ft_convert_num_to_words(num_str, entries);
	ft_free_entries(entries);
	return (0);
}
