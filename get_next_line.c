/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteixeir <dteixeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:40:40 by dteixeir          #+#    #+#             */
/*   Updated: 2021/03/18 21:58:36 by dteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cl(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[256];
	char		buf[BUFFER_SIZE + 1];
	int			fl;
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (!str[fd] && !(str[fd] = ft_calloc(1, sizeof(char *))))
		return (-1);
	while ((cl('\n', str[fd])) < 0 && (fl = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[fl] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
	}
	*line = ft_substr(str[fd], 0, ft_len_gnl(str[fd], 1));
	if ((cl('\n', str[fd])) < 0)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	temp = str[fd];
	str[fd] = ft_substr(str[fd], cl('\n', str[fd]) + 1, ft_len_gnl(str[fd], 0));
	free(temp);
	return (1);
}
