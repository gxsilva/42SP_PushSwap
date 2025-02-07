/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:22:18 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/06 19:24:41 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_rest(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*gnl_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*gnl_content(int fd, char *buffer)
{
	char	*line;
	char	*tmp;
	int		cnt;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	cnt = 1;
	while (!ft_strchr(line, '\n') && cnt > 0)
	{
		cnt = read(fd, line, BUFFER_SIZE);
		if (cnt == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		line[cnt] = 0;
		tmp = ft_strjoin(buffer, line);
		free(buffer);
		buffer = tmp;
	}
	free(line);
	return (buffer);
}
