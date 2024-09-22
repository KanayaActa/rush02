/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:14:26 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 11:16:59 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include "utils.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100000

typedef struct s_entry
{
	char	*key;
	char	*value;
}			t_entry;

typedef struct s_context
{
	char	*num_str;
	int		length;
	int		remaining;
	int		total_chunks;
	t_entry	*entries;
}			t_context;

void		print_error(const char *message);

void		ft_putstr(const char *str);

int			ft_is_valid_num(char *str);

int			ft_is_valid_arg(int ac, char **av, char **num_str, char **dict);

int			ft_is_valid_dict(char *dict);

int			ft_is_zero(const char *str);

char		*ft_read_dict(const char *dict_path);

t_entry		*ft_into_entry(char *dict);

char		*ft_find_word(t_entry *entries, char *search_num);

int			ft_convert_num_to_words(char *num_str, t_entry *entries);

void		handle_hundred_word(t_entry *entries, char *digits);

void		process_hundreds(t_entry *entries, char *digits);

void		handle_teen_word(t_entry *entries, char *digits);

void		handle_tens_word(t_entry *entries, char *digits);

void		handle_units_word(t_entry *entries, char *digits);

void		process_tens_and_units(t_entry *entries, char *digits);

void		handle_magnitude_word(t_entry *entries, char *magnitude_num);

void		process_magnitude(t_context *ctx, int chunk_index);

void		fill_digits_with_zeros(char *digits, int chunk_size);

void		copy_chunk(char *digits, char *num_str, int i, int chunk_size);

void		process_three_digits(t_context *ctx, char *digits, int chunk_index);

void		process_chunks(t_context *ctx);

int			ft_convert_num_to_words(char *num_str, t_entry *entries);

void		free_split(char **split);

char		**split_line(char *line);

char		*process_key(char **sep);

char		*process_value(char **sep);

int			count_size(char **words);

t_entry		parse_line_to_entry(char *line);

t_entry		*ft_into_entry(char *dict);

#endif