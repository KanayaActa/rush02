/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:14:26 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 01:01:37 by miwasa           ###   ########.fr       */
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

// size_t		ft_strlen(const char *str);
// int			ft_strcmp(const char *s1, const char *s2);
// char		*ft_strdup(const char *s);
// char		**ft_split(const char *s, const char *delim);
// char		*ft_strjoin(int count, char **strings, const char *sep);

#endif