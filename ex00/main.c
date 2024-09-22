/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:12:10 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 23:23:54 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	free_numstr_dict(char *dict, char *num_str, int ac)
{
	free(dict);
	if (ac == 1)
		free(num_str);
}

int	is_valid_arg_dict(int ac, char **av, char **num_str, char **dict)
{
	if (!ft_is_valid_arg(ac, av, num_str, dict))
	{
		free_numstr_dict(*dict, *num_str, ac);
		print_error("Error\n");
		return (0);
	}
	if (!ft_is_valid_dict(*dict))
	{
		free_numstr_dict(*dict, *num_str, ac);
		print_error("Dict Error\n");
		return (0);
	}
	return (1);
}

char	*ft_atoa(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	return (str);
}

int	main(int ac, char **av)
{
	char	*dict;
	char	*num_str;
	t_entry	*entries;

	dict = NULL;
	num_str = NULL;
	if (!is_valid_arg_dict(ac, av, &num_str, &dict))
		return (1);
	num_str = ft_atoa(num_str);
	entries = ft_into_entry(dict);
	if (ft_handle_zero(entries, num_str))
	{
		ft_free_entries(entries);
		return (0);
	}
	if (!ft_is_valid_num2(num_str))
		return (1);
	ft_convert_num_to_words(num_str, entries);
	ft_free_entries(entries);
	return (0);
}
