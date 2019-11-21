/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrular <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:59:10 by robrular          #+#    #+#             */
/*   Updated: 2019/11/21 11:38:37 by robrular         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strdup(const char *s1)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	return (ft_strcpy(str, (char *)s1));
}

static char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if ((!(str = (char*)malloc(sizeof(char) * (i + 1)))))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

static	char	*ft_strnew(void)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * (1))))
		return (NULL);
	s[0] = '\0';
	return (s);
}

static char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (ft_strlen(s) > start)
	{
		while (s[start + i] && i < len)
		{
			str[i] = ((char*)s)[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

int				get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*next_l;
	int				c;
	char			*tmp;

	if (!next_l && !(next_l = ft_strnew()))
		return (-1);
	if (!line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0 || BUFFER_SIZE > 100000)
		return (-1);
	while (!(ft_strchr(next_l, '\n')) && (c = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[c] = '\0';
		tmp = next_l;
		next_l = ft_strjoin(tmp, buff);
		free(tmp);
	}
	*line = ft_substr(next_l, 0, ft_linelen(next_l));
	if (ft_get_line(next_l) == NULL)
	{
		free(next_l);
		next_l = NULL;
		return (0);
	}
	return (1);
}
