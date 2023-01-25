/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrani <amrani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:17:19 by kel-amra          #+#    #+#             */
/*   Updated: 2023/01/25 13:23:10 by amrani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	int				j;
	char			*str;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if (len >= (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
