/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:16:26 by fio               #+#    #+#             */
/*   Updated: 2025/05/06 17:10:59 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dest = (char *) malloc (sizeof(char) * (len + 1));
	if (s == NULL || dest == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		len_src;

	len_src = ft_strlen (src);
	dest = (char *) malloc (sizeof (char) * len_src + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	int		len2;
	char	*dest;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof (char) * (len + len2 + 1));
	if (dest == (NULL))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		dest[i + len] = s2[i];
		i++;
	}
	dest[len + len2] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			c2;

	c2 = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c2)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c2)
		return ((char *) &s[i]);
	return (NULL);
}
