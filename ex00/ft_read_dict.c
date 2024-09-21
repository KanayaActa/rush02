/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:32:29 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 01:01:15 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

char	*ft_read_dict(const char *dict_path)
{
	int		fd;
	char	*buffer;
	int		bytes_read;

	if (!dict_path)
	{
		print_error("Dict Error\n");
		return (NULL);
	}
	fd = open(dict_path, O_RDONLY);
	if (fd < 0)
	{
		print_error("Dict Error\n");
		return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		print_error("Error\n");
		close(fd);
		return (NULL);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		print_error("Dict Error\n");
		close(fd);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
}
