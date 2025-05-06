/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:11:10 by fio               #+#    #+#             */
/*   Updated: 2025/05/06 18:25:57 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_build(char *stash, char *buffer)
{
	char	*tmp;

	tmp = NULL;
	if (stash)
	{
		tmp = ft_strdup(stash);
		free(stash);
		if (!tmp)
			return (NULL);
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	else if (stash == NULL && buffer != NULL)
		stash = ft_strdup (buffer);
	return (stash);
}

void	ft_keep_rest(char **ptr)
{
	char	*rest;
	char	*tmp;

	tmp = ft_strchr(*ptr, '\n');
	if (tmp == NULL)
		return ;
	rest = ft_strdup(tmp + 1);
	free (*ptr);
	*ptr = rest;
}

char	*ft_create_line(char **ptr_stash, char **ptr_buffer, ssize_t count)
{
	char	*line;

	line = NULL;
	if (*ptr_stash && **ptr_stash && count == 0)
	{
		line = ft_strdup(*ptr_stash);
		free(*ptr_stash);
		*ptr_stash = NULL;
		free(*ptr_buffer);
		*ptr_buffer = NULL;
		return (line);
	}
	if (*ptr_stash && ft_strchr(*ptr_stash, '\n') != NULL)
	{
		line = ft_substr(*ptr_stash, 0, (ft_strlen(*ptr_stash)
					- ft_strlen(ft_strchr(*ptr_stash, '\n'))) + 1);
		ft_keep_rest(ptr_stash);
		return (line);
	}
	free(*ptr_stash);
	*ptr_stash = NULL;
	free(*ptr_buffer);
	*ptr_buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	ssize_t		count_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = NULL;
	count_read = 1;
	while (count_read != 0)
	{
		if (stash && ft_strchr(stash, '\n') != NULL)
			return (ft_create_line(&stash, &buffer, count_read));
		buffer = (char *) malloc (BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		count_read = read(fd, buffer, BUFFER_SIZE);
		if (count_read <= 0)
			break ;
		buffer[count_read] = '\0';
		stash = ft_build(stash, buffer);
		free(buffer);
		buffer = NULL;
	}
	return (ft_create_line(&stash, &buffer, count_read));
}
