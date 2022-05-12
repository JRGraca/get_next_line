/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:42:34 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/05 15:32:33 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//Gets the line - CORRECT
char	*get_line(char *line)
{
	int		i;
	char	*ret;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	ret = malloc(sizeof(char) * i + 2);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (line[i] != 0 && line[i] != '\n')
	{
		ret[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

//Clears var for next line - CORRECT
char	*next_line(char *new_fd_read)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (new_fd_read[i] && new_fd_read[i] != '\n')
		i++;
	if (!new_fd_read[i])
	{
		free(new_fd_read);
		return (NULL);
	}
	ret = malloc(sizeof(ret) * (ft_strlen(new_fd_read) - i + 1));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (new_fd_read[i] != 0)
	{
		ret[j++] = new_fd_read[i];
		i++;
	}
	ret[j] = '\0';
	free(new_fd_read);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*fd_read;
	char		*temp;
	char		*ret_line;
	int			index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(sizeof(temp) * BUFFER_SIZE + 1);
	index = BUFFER_SIZE;
	while (!ft_strchr(fd_read, '\n') && index != 0)
	{
		index = read(fd, temp, BUFFER_SIZE);
		if (index < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[index] = 0;
		fd_read = ft_strjoin(fd_read, temp);
	}
	free(temp);
	ret_line = get_line(fd_read);
	fd_read = next_line(fd_read);
	return (ret_line);
}
