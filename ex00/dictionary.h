/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:14:26 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 18:24:00 by miwasa           ###   ########.fr       */
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
	int		total_chunks;
	int		remaining;
	t_entry	*entries;
	int		is_first;
}			t_context;

typedef struct s_flag
{
	int		and;
	int		hyphen;
	int		comma;
}			t_flag;

void		print_error(const char *message);

void		ft_putstr(const char *str);

int			ft_is_valid_num(char *str);

int			ft_is_valid_arg(int ac, char **av, char **num_str, char **dict);

int			ft_is_valid_dict(char *dict);

int			ft_is_zero(const char *str);

char		*ft_read_dict(const char *dict_path);

t_entry		*ft_into_entry(char *dict);

char		*ft_find_word(t_entry *entries, char *search_num);

void		ft_convert_num_to_words(char *num_str, t_entry *entries);

void		handle_hundred_word(t_entry *entries, char *digits, t_context *ctx,
				t_flag *fg);

void		process_hundreds(t_entry *entries, char *digits, t_context *ctx,
				t_flag *fg);

void		handle_teen_word(t_entry *entries, char *digits, t_context *ctx,
				t_flag *fg);

void		handle_tens_word(t_entry *entries, char *digits, t_context *ctx,
				t_flag *fg);

void		handle_units_word(t_entry *entries, char *digits, t_context *ctx,
				t_flag *fg);

void		process_tens_and_units(t_entry *entries, char *digits,
				t_context *ctx, t_flag *fg);

void		handle_magnitude_word(t_entry *entries, char *magnitude_num,
				t_context *ctx, t_flag *fg);

void		process_magnitude(t_context *ctx, int chunk_index, t_flag *fg);

void		fill_digits_with_zeros(char *digits, int chunk_size);

void		copy_chunk(char *digits, char *num_str, int i, int chunk_size);

void		process_three_digits(t_context *ctx, char *digits, int chunk_index,
				t_flag *fg);

void		process_chunks(t_context *ctx);

void		free_split(char **split);

char		**split_line(char *line);

char		*process_key(char **sep);

char		*process_value(char **sep);

int			count_size(char **words);

t_entry		parse_line_to_entry(char *line);

t_entry		*ft_into_entry(char *dict);

int			ft_handle_zero(t_entry *entries, char *num_str);

void		ft_free_entries(t_entry *entries);

char		*ft_stdin(void);

void		initialize_result(char **result, size_t *result_size);
char		*append_buffer(char *result, size_t result_size, char *buffer,
				ssize_t bytes_read);
int			find_newline(char *buffer, ssize_t bytes_read);
void		finalize_result(char *result, size_t result_size);

#endif
