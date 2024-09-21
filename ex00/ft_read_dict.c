/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:28:39 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 02:30:26 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	open_dict(const char *dict_path)
{
	int	fd;

	if (!dict_path)
	{
		print_error("Dict Error\n");
		return (-1);
	}
	fd = open(dict_path, O_RDONLY);
	if (fd < 0)
	{
		print_error("Dict Error\n");
		return (-1);
	}
	return (fd);
}

char	*read_file_to_buffer(int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		print_error("Error\n");
		return (NULL);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		print_error("Dict Error\n");
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*ft_read_dict(const char *dict_path)
{
	int		fd;
	char	*buffer;

	fd = open_dict(dict_path);
	if (fd < 0)
		return (NULL);
	buffer = read_file_to_buffer(fd);
	close(fd);
	return (buffer);
}
