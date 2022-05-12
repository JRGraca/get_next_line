/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:07:58 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/04 16:11:56 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	i = -1;
	j = 0;
	result = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (result == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			result[i] = s1[i];
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (c == 0)
		return (&s[ft_strlen(s)]);
	while (s[i] != 0)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
