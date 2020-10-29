/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:24:30 by oren              #+#    #+#             */
/*   Updated: 2020/10/29 21:21:28 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reset_text(int i, char *extra_words)
{
	char	*dest;
	int		j;

	j = i;
	while (extra_words[j])
		j++;
	if (!(dest = malloc(sizeof(char) * j + 1)))
		return (0);
	j = 0;
	while (extra_words[i])
	{
		dest[j] = extra_words[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int		is_end(char *extra_char)
{
	int i;

	i = 0;
	while (extra_char && extra_char[i])
	{
		if (extra_char[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	static char *extra_char = NULL;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) == -1)
		return (-1);
	while ((is_end(extra_char) == -1) && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		extra_char = ft_strjoin(extra_char, buf);
	}
	if (is_end(extra_char) > -1)
	{
		*line = ft_strndup(extra_char, is_end(extra_char));
		temp = reset_text((is_end(extra_char) + 1), extra_char);
		ft_free(extra_char);
		extra_char = ft_strndup(temp, ft_strlen(temp));
		ft_free(temp);
		return (1);
	}
	*line = ft_strndup(extra_char, ft_strlen(extra_char));
	ft_free(extra_char);
	extra_char = NULL;
	return (0);
}
