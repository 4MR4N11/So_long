/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:59:04 by kel-amra          #+#    #+#             */
/*   Updated: 2021/12/21 03:04:59 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*joiner(int i, char *str)
{
	char	*s;

	s = malloc(sizeof(char) * (BUFFER_SIZE + i + 1));
	if (!s)
		return (NULL);
	ft_memcpy(s, str, i);
	free(str);
	return (s);
}

static char	*cleaner(char *str)
{
	char	*tmp;

	tmp = ft_strdup(str);
	free(str);
	return (tmp);
}

static char	*checker(int byte, int i, int n, char *str)
{
	if (n == 0)
	{
		if (i == 0 && byte == 0)
		{
			free(str);
			return (NULL);
		}
		if (str)
			return (str);
	}				
	if (n == -1)
	{
		free (str);
		return (NULL);
	}
	return (NULL);
}

static char	*reader(int fd, char *str, char c)
{
	int		n;
	int		i;
	int		byte;

	n = 0;
	i = 0;
	byte = 0;
	while (1)
	{
		i = 0;
		while (i < BUFFER_SIZE && c != '\n')
		{
			n = read(fd, &c, 1);
			if (n == 0 || n == -1)
				return (checker(byte, i, n, str));
			str[i++ + byte] = c;
			str[i + byte] = '\0';
		}
		byte += i;
		if (c == '\n')
			return (cleaner(str));
		str = joiner(byte, str);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*str;

	c = 0;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	return (reader(fd, str, c));
}
