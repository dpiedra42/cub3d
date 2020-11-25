/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:21:22 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/11/25 15:53:29 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_new(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(sjoin = malloc(sizeof(char) * ((len1 + len2) + 1))))
		return (NULL);
	ft_memmove(sjoin, s1, len1);
	ft_memmove(sjoin + len1, s2, len2);
	sjoin[len1 + len2] = '\0';
	free((void *)s1);
	return (sjoin);
}

char	*get_line(char *s1)
{
	int		i;
	char	*lineread;

	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
		i++;
	if (!(lineread = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		lineread[i] = s1[i];
		i++;
	}
	lineread[i] = '\0';
	return (lineread);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dest;
	unsigned char *source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dest < source)
	{
		while (len--)
		{
			*dest = *source;
			dest++;
			source++;
		}
	}
	else if (dest > source)
		while (len--)
			*(dest + len) = *(source + len);
	return (dst);
}
