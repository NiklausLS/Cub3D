/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:59:51 by nileempo          #+#    #+#             */
/*   Updated: 2024/02/09 19:18:22 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *memory, char *buf)
{
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!memory)
	{
		memory = (char *)malloc(sizeof(char) * 1);
		memory[0] = '\0';
	}
	dest = malloc(sizeof(char) * (ft_gnl_strlen(memory)
				+ (ft_gnl_strlen(buf) + 1)));
	if (!dest)
		return (NULL);
	while (memory[++i])
		dest[i] = memory[i];
	while (buf[++j])
		dest[i + j] = buf[j];
	dest[i + j] = '\0';
	free(memory);
	return (dest);
}

char	*ft_gnl_strchr(char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	if (c == '\0')
		return (ptr + ft_gnl_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
