/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:25:22 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/13 16:16:52 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus.h"

int	map_component_checker(t_data *tmp)
{
	int	i;

	i = -1;
	close (tmp->fd);
	if (tmp->collectible < 1 || tmp->emty_space < 1
		|| tmp->map_exit < 1 || tmp->p_start_position != 1)
		return (free_data(tmp->map));
	while (tmp->map[++i])
	{
		if (tmp->ll != (int)ft_strlen(tmp->map[i]) && i != tmp->lines - 1)
			return (free_data(tmp->map));
		if ((i == tmp->lines -1) && (tmp->ll -1 != (int)ft_strlen(tmp->map[i])))
			return (free_data(tmp->map));
	}
	return (0);
}

int	map_extension_checker(char *map)
{
	int		i;
	int		index;
	char	*str;

	str = ft_strdup(".ber");
	index = ft_strlen(map) - 1;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] != map[index])
		{
			free(str);
			return (1);
		}
		i--;
		index--;
	}
	free(str);
	return (0);
}

int	walls_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
		{
			if (str[i] == '\n' && str[i + 1] == '\0')
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

int	errors_check(int ac, t_data *tmp, char *str)
{
	if (ac != 2)
		return (ft_printf("Error : invalid arguments\n"), 2);
	if (map_extension_checker(str))
		return (ft_printf("Error : map invalid\n"), 2);
	tmp->fd_tmp = open(str, O_RDONLY);
	if (tmp->fd_tmp < 0)
		return (ft_printf("Error : map invalid\n"), 2);
	tmp->lines = line_counter(tmp->fd_tmp);
	close (tmp->fd_tmp);
	if (tmp->lines == 0)
		return (ft_printf("Error : map invalid\n"), 2);
	tmp->h = tmp->lines;
	tmp->fd = open (str, O_RDONLY);
	if (tmp->fd < 0)
		return (ft_printf("Error : map invalid\n"), 2);
	tmp->msg = parsing(tmp);
	if (tmp->msg == 1)
	{
		close (tmp->fd);
		return (ft_printf("Error : map invalid\n"), 2);
	}
	return (0);
}
