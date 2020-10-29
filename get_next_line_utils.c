/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:24:43 by oren              #+#    #+#             */
/*   Updated: 2020/10/29 21:21:18 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char *s, int n)
{
	char	*dest;
	int		i;

	if (!(dest = malloc(sizeof(char) * (n + 1))))
		return (0);
	i = 0;
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free(char *s)
{
	free(s);
	s = NULL;
}

size_t	ft_strlen(char *s)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		size;

	if (!s1)
	{
		if (!(s1 = malloc(sizeof(char) * 1)))
			return (0);
		s1[0] = '\0';
	}
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = malloc(sizeof(char) * (size + 1))))
	{
		ft_free(s1);
		return (0);
	}
	dest = fill_dest(dest, s1, s2);
	ft_free(s1);
	return (dest);
}

char	*fill_dest(char *dest, char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[j + i] = s2[j];
		j++;
	}
	dest[j + i] = '\0';
	return (dest);
}
