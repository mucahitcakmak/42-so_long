/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:52:52 by museker           #+#    #+#             */
/*   Updated: 2023/08/08 00:15:51 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_read(char *str, int fd)
{
	char	*temp;
	int		byte;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byte = 1;
	while (!new_check(str) && byte != 0)
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte == -1)
		{
			if (str)
				free(str);
			free(temp);
			return (NULL);
		}
		temp[byte] = '\0';
		str = ft_strjoin_gnl(str, temp);
	}
	free(temp);
	return (str);
}

char	*ft_getline(char *s)
{
	int		i;
	char	*arr;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			break ;
	if (s[i] == '\n')
		i++;
	arr = malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_cutline(char *str)
{
	char	*cuttedline;
	int		start; 
	int		len;
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			break ;
	if (str[i] == '\n')
		i++;
	start = i;
	len = (ft_strlen(str) - start);
	if (len == 0)
	{
		free(str);
		return (NULL);
	}
	cuttedline = ft_substr(str, start, len);
	free (str);
	return (cuttedline);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(str, fd);
	if (!str || !*str)
	{
		if (str)
			free(str);
		str = NULL;
		return (NULL);
	}
	line = ft_getline(str);
	str = ft_cutline(str);
	if (line[0] == '\n')
	{
		if (str)
			free(str);
		str = NULL;
		return (NULL);
	}
	return (line);
}
