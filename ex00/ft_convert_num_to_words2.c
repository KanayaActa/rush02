/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num_to_words2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 04:47:02 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 04:51:04 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	process_tens_and_units(t_entry *entries, char *digits)
{
	if (digits[1] == '1')
	{
		handle_teen_word(entries, digits);
	}
	else
	{
		if (digits[1] != '0')
			handle_tens_word(entries, digits);
		if (digits[2] != '0')
		{
			if (digits[1] != '0')
				ft_putstr(" ");
			handle_units_word(entries, digits);
		}
	}
}

void	handle_magnitude_word(t_entry *entries, char *magnitude_num)
{
	char	*word;

	word = ft_find_word(entries, magnitude_num);
	if (word)
	{
		ft_putstr(" ");
		ft_putstr(word);
		free(word);
	}
}

void	process_magnitude(t_context *ctx, int chunk_index)
{
	int		i;
	int		num_zeros;
	char	*magnitude_num;

	i = 1;
	if (chunk_index > 0)
	{
		num_zeros = chunk_index * 3;
		magnitude_num = malloc(2 + num_zeros);
		if (!magnitude_num)
		{
			print_error("Error\n");
			return ;
		}
		magnitude_num[0] = '1';
		while (i <= num_zeros)
		{
			magnitude_num[i] = '0';
			i++;
		}
		magnitude_num[num_zeros + 1] = '\0';
		handle_magnitude_word(ctx->entries, magnitude_num);
		free(magnitude_num);
	}
}

void	fill_digits_with_zeros(char *digits, int chunk_size)
{
	int	j;

	j = 0;
	while (j < (3 - chunk_size))
	{
		digits[j] = '0';
		j++;
	}
}

void	copy_chunk(char *digits, char *num_str, int i, int chunk_size)
{
	int	j;

	j = 0;
	while (j < chunk_size)
	{
		digits[j + (3 - chunk_size)] = num_str[i + j];
		j++;
	}
	digits[3] = '\0';
}
