/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num_to_words3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 04:49:02 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 11:38:20 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

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

void	process_three_digits(t_context *ctx, char *digits, int chunk_index)
{
	process_hundreds(ctx->entries, digits, ctx);
	process_tens_and_units(ctx->entries, digits, ctx);
	process_magnitude(ctx, chunk_index);
}

void	process_chunks(t_context *ctx)
{
	int		chunk_index;
	int		i;
	int		chunk_size;
	char	digits[4];

	chunk_index = ctx->total_chunks - 1;
	i = 0;
	while (i < ctx->length)
	{
		if (chunk_index == ctx->total_chunks - 1)
			chunk_size = ctx->remaining;
		else
			chunk_size = 3;
		fill_digits_with_zeros(digits, chunk_size);
		copy_chunk(digits, ctx->num_str, i, chunk_size);
		if (!(digits[0] == '0' && digits[1] == '0' && digits[2] == '0'))
		{
			process_three_digits(ctx, digits, chunk_index);
		}
		i += chunk_size;
		chunk_index--;
	}
}

void	ft_convert_num_to_words(char *num_str, t_entry *entries)
{
	t_context	ctx;

	ctx.num_str = num_str;
	ctx.length = ft_strlen(num_str);
	ctx.total_chunks = ctx.length / 3;
	if (ctx.length % 3)
		ctx.total_chunks++;
	ctx.remaining = ctx.length % 3;
	if (ctx.remaining == 0)
		ctx.remaining = 3;
	ctx.entries = entries;
	ctx.is_first = 1;
	process_chunks(&ctx);
}
