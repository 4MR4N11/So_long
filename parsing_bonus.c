/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:06:14 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/13 20:06:37 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus.h"

int	free_data(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free (str[i]);
		str[i] = NULL;
		i++;
	}
	free (str);
	str = NULL;
	return (1);
}

int	map_component(char *str, t_data *tmp)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i + 1] != '\0')
	{
		if (str[i] == '0')
			tmp->emty_space++;
		else if (str[i] == 'C')
			tmp->collectible++;
		else if (str[i] == 'E')
			tmp->map_exit++;
		else if (str[i] == 'P')
			tmp->p_start_position++;
		else if (str[i] == '1')
			tmp->wall_num++;
		else if (str[i] == 'X')
			tmp->enemy++;
		else
			return (1);
		i++;
	}
	return (0);
}

static	int	get_line_len(t_data *tmp)
{
	int	i;

	i = 0;
	while (i <= tmp->lines)
	{
		tmp->map[i] = NULL;
		i++;
	}
	i = 0;
	tmp->map[i] = get_next_line(tmp->fd);
	if (!tmp->map[i])
		return (1);
	tmp->ll = ft_strlen(tmp->map[i]);
	tmp->w = tmp->ll;
	return (0);
}

int	parsing(t_data *tmp)
{
	int	i;

	i = 0;
	tmp->map = malloc(sizeof(char *) * (tmp->lines + 1));
	if (!tmp->map)
		return (1);
	if (get_line_len(tmp))
		return (1);
	while (tmp->map && tmp->map[i])
	{
		if (tmp->map[i][0] != '1' || tmp->map[i][tmp->ll - 2] != '1')
			return (free_data(tmp->map));
		if (i == tmp->lines - 1 || i == 0)
		{
			if (walls_checker(tmp->map[i]))
				return (free_data(tmp->map));
		}
		if (map_component(tmp->map[i], tmp))
			return (free_data(tmp->map));
		tmp->map[++i] = get_next_line(tmp->fd);
	}
	return (map_component_checker(tmp));
}
