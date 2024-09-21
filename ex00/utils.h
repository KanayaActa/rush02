/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:51:05 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 00:03:46 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

int		ft_strlen(char *str);

void	ft_strcat(char *dest, char *src);

char	*ft_strdup(char *src);

int		ft_strcmp(char *s1, char *s2);

char	*ft_strjoin(int size, char **strs, char *sep);

char	**ft_split(char *str, char *charset);

#endif
