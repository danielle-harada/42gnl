/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteixeir <dteixeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:40:16 by dteixeir          #+#    #+#             */
/*   Updated: 2021/03/18 21:56:35 by dteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len_gnl(const char *str, int gnl)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && gnl)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_len_gnl(s1, 0) + ft_len_gnl(s2, 0) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	str[i + j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	if (!s)
		return (NULL);
	if (start > ft_len_gnl(s, 0))
		return (NULL);
	sub_str = malloc(1 + len * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (s[start] && len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
		len--;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
