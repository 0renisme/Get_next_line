#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	ft_free(char *s)
{
	free(s);
	s = NULL;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;

	if (!(dest = malloc(sizeof(char) * (len - start + 1))))
		return (0);
	i = 0;
	while (s && s[start] && start < len)
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		if (!(s1 = malloc(sizeof(char))))
			return (0);
		s1[0] = 0;
	}
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	free(s1);
	return (dest);
}

