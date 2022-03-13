/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:16:34 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/13 15:04:17 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus.h"

int	close_window(t_data *tmp)
{
	mlx_destroy_window(tmp->mlx, tmp->win);
	exit(0);
	return (0);
}

int	get_event(int keycode, t_data *tmp)
{
	tmp->x = 0;
	tmp->y = 0;
	if (keycode == ESC)
		return (close_window(tmp));
	else if (keycode == UP)
		player_up(tmp, tmp->p_y, tmp->p_x);
	else if (keycode == DOWN)
		player_down(tmp, tmp->p_y, tmp->p_x);
	else if (keycode == LEFT)
		player_left(tmp, tmp->p_y, tmp->p_x);
	else if (keycode == RIGHT)
		player_right(tmp, tmp->p_y, tmp->p_x);
	mlx_string_put(tmp->mlx, tmp->win, 10, 10, 0x002C3E50, ft_itoa(tmp->mv));
	return (0);
}
