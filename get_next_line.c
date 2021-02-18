/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oren <orfreoua@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 03:13:17 by oren              #+#    #+#             */
/*   Updated: 2021/02/18 03:28:12 by oren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

short	find_nl(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

short	fill_rest(char **rest, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int			ret;

	while ((find_nl(*rest) == -1) && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (!(*rest = ft_strjoin(*rest, buf)))
			return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest = NULL;
	char		*temp;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || read(fd, temp, 0) == -1)
		return (-1);
	if (!(fill_rest(&rest, fd)))
		return(-1);
	if (find_nl(rest) > -1)
	{
		if (!(*line = ft_substr(rest, 0, find_nl(rest))))
			return (-1);
		if (!(temp = ft_substr(rest, (find_nl(rest) + 1), ft_strlen(rest))))
			return (-1);
		ft_free(rest);
		if (!(rest = ft_substr(temp, 0, ft_strlen(temp))))
			return (-1);
		ft_free(temp);
		return (1);
	}
	if (!(*line = ft_substr(rest, 0, ft_strlen(rest))))
		return (-1);
	ft_free(rest);
	rest = NULL;
	return (0);
}
