/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:08:32 by miwasa            #+#    #+#             */
/*   Updated: 2024/09/22 16:10:42 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

char	*append_buffer(char *result, size_t result_size, char *buffer,
			ssize_t bytes_read);
int		find_newline(char *buffer, ssize_t bytes_read);
void	initialize_result(char **result, size_t *result_size);
void	trim_newline(char *result, size_t result_size);
int		read_repeat(char **result, size_t *result_size, ssize_t *bytes_read);

char	*ft_stdin(void)
{
	char	*result;
	size_t	result_size;
	ssize_t	bytes_read;
	int		ret;

	initialize_result(&result, &result_size);
	ret = read_repeat(&result, &result_size, &bytes_read);
	if (ret == 0)
		return (NULL);
	if (ret == -1)
		return (result);
	if (bytes_read == -1)
	{
		free(result);
		return (NULL);
	}
	if (result && result_size > 0 && result[result_size - 1] == '\n')
		result[result_size - 1] = '\0';
	return (result);
}

int	read_repeat(char **result, size_t *result_size, ssize_t *bytes_read)
{
	char	buffer[1024];
	int		newline_index;

	while (1)
	{
		*bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
		if (*bytes_read <= 0)
			break ;
		*result = append_buffer(*result, *result_size, buffer, *bytes_read);
		if (!*result)
			return (0);
		*result_size += *bytes_read;
		newline_index = find_newline(buffer, *bytes_read);
		if (newline_index != -1)
		{
			(*result)[*result_size - *bytes_read + newline_index] = '\0';
			return (-1);
		}
	}
	return (1);
}

char	*append_buffer(char *result, size_t result_size, char *buffer,
		ssize_t bytes_read)
{
	char	*new_result;
	size_t	i;

	new_result = malloc(result_size + bytes_read + 1);
	if (!new_result)
	{
		free(result);
		return (NULL);
	}
	i = -1;
	while (++i < result_size)
		new_result[i] = result[i];
	i = -1;
	while (++i < (size_t)bytes_read)
		new_result[result_size + i] = buffer[i];
	new_result[result_size + bytes_read] = '\0';
	free(result);
	return (new_result);
}

int	find_newline(char *buffer, ssize_t bytes_read)
{
	ssize_t	i;

	i = -1;
	while (++i < bytes_read)
	{
		if (buffer[i] == '\n')
			return (i);
	}
	return (-1);
}

void	initialize_result(char **result, size_t *result_size)
{
	*result = NULL;
	*result_size = 0;
}
