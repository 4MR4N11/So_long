/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrani <amrani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:11:43 by kel-amra          #+#    #+#             */
/*   Updated: 2023/01/25 13:23:03 by amrani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_len(int n)
{	
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len(n);
	if (n == 0)
		return (ft_strdup("0\0"));
	nb = malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (NULL);
	if (n < 0)
	{
		nb[0] = '-';
		n *= -1;
	}
	nb[len] = '\0';
	while (n > 0)
	{
		nb[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (nb);
}
