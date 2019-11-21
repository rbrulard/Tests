/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrular <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:24:42 by robrular          #+#    #+#             */
/*   Updated: 2019/11/19 11:57:00 by robrular         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(s) + 1)
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
	return (NULL);
}

int		ft_linelen(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_get_line(char *str)
{
	if (ft_strchr(str, '\n'))
	{
		ft_strcpy(str, ft_strchr(str, '\n') + 1);
		return (str);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
