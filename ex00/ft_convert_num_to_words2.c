/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num_to_words2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 04:47:02 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 18:22:12 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	process_tens_and_units(t_entry *entries, char *digits, t_context *ctx,
		t_flag *fg)
{
	fg->hyphen = 0;
	if (digits[1] == '1')
	{
		handle_teen_word(entries, digits, ctx, fg);
	}
	else
	{
		if (digits[1] != '0')
		{
			fg->hyphen = 1;
			handle_tens_word(entries, digits, ctx, fg);
		}
		if (digits[2] != '0')
		{
			handle_units_word(entries, digits, ctx, fg);
		}
	}
}

void	handle_magnitude_word(t_entry *entries, char *magnitude_num,
		t_context *ctx, t_flag *fg)
{
	char	*word;

	word = ft_find_word(entries, magnitude_num);
	if (word)
	{
		fg->comma = 1;
		if (!ctx->is_first)
			ft_putstr(" ");
		ft_putstr(word);
		free(word);
		ctx->is_first = 0;
	}
}

void	process_magnitude(t_context *ctx, int chunk_index, t_flag *fg)
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
		fg->comma = 1;
		handle_magnitude_word(ctx->entries, magnitude_num, ctx, fg);
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
