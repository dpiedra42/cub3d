/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:15:26 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/07/07 18:24:24 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*del_line(char *s)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	if (!(newstr = malloc(sizeof(char) * (ft_strlen(s)) - i + 1)))
		return (NULL);
	j = 0;
	i++;
	while (s[i] != '\0')
	{
		newstr[j] = s[i];
		j++;
		i++;
	}
	free(s);
	newstr[j] = '\0';
	return (newstr);
}


int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*str;
	int			red;

	if (fd < 0 || !line || 1 <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * 1 + 1)))
		return (-1);
	red = 1;
	while ((red != 0) && (check_new(str) != 1))
	{
		red = read(fd, buf, 1);
		if (red == -1)
			return (-1);
		buf[red] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	*line = get_line(str);
	str = del_line(str);
	if (red == 0)
		return (0);
	return (1);
}