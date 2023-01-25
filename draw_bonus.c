/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrani <amrani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:14:26 by kel-amra          #+#    #+#             */
/*   Updated: 2023/01/25 13:46:39 by amrani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus.h"

void	drawer(t_data *tmp)
{
	int	i;
	int	q;
	int	j;

	j = 0;
	i = -1;
	while (tmp->map && tmp->map[++i])
	{
		tmp->y = tmp->y + j;
		q = -1;
		while (tmp->map[i][++q])
			put_square(tmp, i, q);
		j = 32;
		tmp->x = 0;
	}
}

void	draw(t_data *tmp)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	tmp->mv = 0;
	tmp->x = 0;
	tmp->y = 0;
	tmp->player_color = 0x00FFFFFF;
	initialisation(tmp);
	drawer(tmp);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img, 0, 0);
	mlx_string_put(tmp->mlx, tmp->win, 10, 10, 0x002C3E50, ft_itoa(tmp->mv));
	mlx_hook(tmp->win, 2, 1L<<0, get_event, tmp);
	mlx_hook(tmp->win, 17, 0, close_window, tmp);
	mlx_loop(tmp->mlx);
}
