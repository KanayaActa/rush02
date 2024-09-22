/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num_to_words.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 03:39:11 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 15:32:07 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	handle_hundred_word(t_entry *entries, char *digits, t_context *ctx)
{
	char	*word;

	word = ft_find_word(entries, digits);
	if (word)
	{
		if (!ctx->is_first)
			ft_putstr(" ");
		ft_putstr(word);
		free(word);
		ctx->is_first = 0;
	}
}

void	process_hundreds(t_entry *entries, char *digits, t_context *ctx)
{
	char	hundred_str[2];

	hundred_str[0] = digits[0];
	hundred_str[1] = '\0';
	if (digits[0] != '0')
	{
		handle_hundred_word(entries, hundred_str, ctx);
		ft_putstr(" ");
		handle_hundred_word(entries, "100", ctx);
		if (digits[1] != '0' || digits[2] != '0')
			ft_putstr(" ");
	}
}

void	handle_teen_word(t_entry *entries, char *digits, t_context *ctx)
{
	char	teen_str[3];
	char	*word;

	teen_str[0] = digits[1];
	teen_str[1] = digits[2];
	teen_str[2] = '\0';
	word = ft_find_word(entries, teen_str);
	if (word)
	{
		if (!ctx->is_first)
			ft_putstr(" ");
		ft_putstr(word);
		free(word);
		ctx->is_first = 0;
	}
}

void	handle_tens_word(t_entry *entries, char *digits, t_context *ctx)
{
	char	ten_str[3];
	char	*word;

	ten_str[0] = digits[1];
	ten_str[1] = '0';
	ten_str[2] = '\0';
	word = ft_find_word(entries, ten_str);
	if (word)
	{
		if (!ctx->is_first)
			ft_putstr(" ");
		ft_putstr(word);
		free(word);
		ctx->is_first = 0;
	}
}

void	handle_units_word(t_entry *entries, char *digits, t_context *ctx)
{
	char	unit_str[2];
	char	*word;

	unit_str[0] = digits[2];
	unit_str[1] = '\0';
	word = ft_find_word(entries, unit_str);
	if (word)
	{
		if (!ctx->is_first)
			ft_putstr(" ");
		ft_putstr(word);
		free(word);
		ctx->is_first = 0;
	}
}
