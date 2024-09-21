/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num_to_words.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:57:15 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 01:04:34 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	process_hundreds(t_entry *entries, char *digits)
{
	char	*word;
	char	hundred_str[2] = {digits[0], '\0'};

	if (digits[0] != '0')
	{
		word = ft_find_word(entries, hundred_str);
		if (word)
		{
			ft_putstr(word);
			free(word);
		}
		ft_putstr(" ");
		word = ft_find_word(entries, "100");
		if (word)
		{
			ft_putstr(word);
			free(word);
		}
		if (digits[1] != '0' || digits[2] != '0')
			ft_putstr(" ");
	}
}

void	process_tens_and_units(t_entry *entries, char *digits)
{
	char	*word;
	char	teen_str[3] = {digits[1], digits[2], '\0'};
	char	ten_str[3] = {digits[1], '0', '\0'};
	char	unit_str[2] = {digits[2], '\0'};

	if (digits[1] == '1')
	{
		word = ft_find_word(entries, teen_str);
		if (word)
		{
			ft_putstr(word);
			free(word);
		}
	}
	else
	{
		if (digits[1] != '0')
		{
			word = ft_find_word(entries, ten_str);
			if (word)
			{
				ft_putstr(word);
				free(word);
			}
			if (digits[2] != '0')
				ft_putstr(" ");
		}
		if (digits[2] != '0')
		{
			word = ft_find_word(entries, unit_str);
			if (word)
			{
				ft_putstr(word);
				free(word);
			}
		}
	}
}

void	process_magnitude(t_entry *entries, int chunk_index)
{
	char	*word;
	char	*magnitude_num;
	int		pos;
	int		num_zeros;

	if (chunk_index > 0)
	{
		num_zeros = chunk_index * 3;
		magnitude_num = malloc(1 + num_zeros + 1); // '1' + '0's + '\0'
		if (!magnitude_num)
		{
			print_error("Error\n");
			exit(1);
		}
		pos = 0;
		magnitude_num[pos++] = '1';
		for (int i = 0; i < num_zeros; i++)
			magnitude_num[pos++] = '0';
		magnitude_num[pos] = '\0';
		word = ft_find_word(entries, magnitude_num);
		if (word)
		{
			ft_putstr(" ");
			ft_putstr(word);
			free(word);
		}
		free(magnitude_num);
	}
}

void	process_three_digits(t_entry *entries, char *digits, int chunk_index)
{
	process_hundreds(entries, digits);
	process_tens_and_units(entries, digits);
	process_magnitude(entries, chunk_index);
}

void	process_chunks(char *num_str, int length, int remaining,
		int total_chunks, t_entry *entries)
{
	int		chunk_index;
	int		chunk_size;
	char	*digits;
	int		i;

	digits = malloc(4);
	if (!digits)
	{
		print_error("Error\n");
		exit(1);
	}
	i = 0;
	chunk_index = total_chunks - 1;
	while (i < length)
	{
		chunk_size = (chunk_index == total_chunks - 1) ? remaining : 3;
		if (chunk_size == 0)
			chunk_size = 3; // 防止 chunk_size が 0 になる
		for (int j = 0; j < (3 - chunk_size); j++)
			digits[j] = '0';
		for (int j = 0; j < chunk_size; j++)
			digits[j + (3 - chunk_size)] = num_str[i + j];
		digits[3] = '\0';
		if (!(digits[0] == '0' && digits[1] == '0' && digits[2] == '0'))
		{
			process_three_digits(entries, digits, chunk_index);
			if (i + chunk_size < length)
				ft_putstr(" ");
		}
		i += chunk_size;
		chunk_index--;
	}
	free(digits);
}

int	ft_convert_num_to_words(char *num_str, t_entry *entries)
{
	int	length;
	int	total_chunks;
	int	remaining;

	length = ft_strlen(num_str);
	total_chunks = length / 3;
	if (length % 3)
		total_chunks++;
	remaining = length % 3;
	if (remaining == 0)
		remaining = 3;
	process_chunks(num_str, length, remaining, total_chunks, entries);
	return (1);
}
