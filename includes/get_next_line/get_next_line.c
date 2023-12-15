/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:27:01 by atudor            #+#    #+#             */
/*   Updated: 2023/10/22 17:44:35 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line/get_next_line.h"
#include "../../includes/ft_push_swap.h"

char	*true_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*update_storage(char *storage)
{
	char	*new_storage;
	int		i;

	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	i++;
	new_storage = ft_substr(storage, i, ft_strlen(storage));
	free(storage);
	return (new_storage);
}

char	*only_line(char	*storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	i++;
	line = ft_substr(storage, 0, i);
	return (line);
}

char	*fill_storage(int fd, char *storage)
{
	int		num_bytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (true_free(&storage));
	buffer[0] = '\0';
	num_bytes = 1;
	while (num_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(buffer);
			return (true_free(&storage));
		}
		if (num_bytes > 0)
		{
			buffer[num_bytes] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = fill_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = only_line(storage);
	if (!line)
		return (true_free(&storage));
	storage = update_storage(storage);
	return (line);
}
