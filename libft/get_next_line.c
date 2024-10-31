/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:58:37 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/09 19:18:01 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buf(int fd, char *memory)
{
	int		rd;
	char	*buf;

	rd = 1;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(memory);
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		memory = ft_gnl_strjoin(memory, buf);
		if (ft_gnl_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (memory);
}

static char	*gt_line(char *memory)
{
	int		i;
	char	*line;

	i = 0;
	if (memory[i] == '\0')
		return (NULL);
	while (memory[i] && memory[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] == '\n')
	{
		line[i] = memory[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_last(char *memory)
{
	int		i;
	int		j;
	char	*last;

	i = 0;
	j = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (memory[i] == '\0')
	{
		free(memory);
		return (NULL);
	}
	last = (char *)malloc(sizeof(char) * (ft_gnl_strlen(memory) - i + 1));
	if (!last)
		return (NULL);
	i++;
	while (memory[i])
		last[j++] = memory[i++];
	last[j] = '\0';
	return (last);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory = get_buf(fd, memory);
	if (!memory)
		return (NULL);
	line = gt_line(memory);
	if (!line && !memory)
		return (NULL);
	memory = get_last(memory);
	return (line);
}
