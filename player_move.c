/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrani <amrani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:17:03 by kel-amra          #+#    #+#             */
/*   Updated: 2023/01/25 13:23:21 by amrani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static	void	draw_loop(t_data *tmp)
{
	mlx_destroy_image(tmp->mlx, tmp->img);
	initialisation(tmp);
	ft_printf("%d\n", tmp->mv);
	drawer(tmp);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img, 0, 0);
}

void	player_up(t_data *tmp, int i, int j)
{
	if (tmp->map[i - 1][j] != '1' && tmp->map[i - 1][j] != 'E')
	{
		++tmp->mv;
		if (tmp->map[i - 1][j] == 'C')
		{
			tmp->collectible--;
			tmp->map[i - 1][j] = tmp->map[i][j];
			tmp->map[i][j] = '0';
		}
		else
			change_pos(tmp, i, j, 0);
	}
	if (tmp->map[i - 1][j] == 'E' && tmp->collectible == 0)
	{
		change_pos(tmp, i, j, 0);
		draw_loop(tmp);
		mlx_destroy_image(tmp->mlx, tmp->img);
		mlx_clear_window(tmp->mlx, tmp->win);
		ft_printf("YOU WON\n");
		ft_printf("-------\n");
		exit(0);
	}
	draw_loop(tmp);
}

void	player_down(t_data *tmp, int i, int j)
{
	if (tmp->map[i + 1][j] != '1' && tmp->map[i + 1][j] != 'E')
	{
		++tmp->mv;
		if (tmp->map[i + 1][j] == 'C')
		{
			tmp->collectible--;
			tmp->map[i + 1][j] = tmp->map[i][j];
			tmp->map[i][j] = '0';
		}
		else
			change_pos(tmp, i, j, 1);
	}
	if (tmp->map[i + 1][j] == 'E' && tmp->collectible == 0)
	{
		change_pos(tmp, i, j, 1);
		draw_loop(tmp);
		mlx_destroy_image(tmp->mlx, tmp->img);
		mlx_clear_window(tmp->mlx, tmp->win);
		ft_printf("YOU WON\n");
		ft_printf("-------\n");
		exit(0);
	}
	draw_loop(tmp);
}

void	player_right(t_data *tmp, int i, int j)
{
	if (tmp->map[i][j + 1] != '1' && tmp->map[i][j + 1] != 'E')
	{
		++tmp->mv;
		if (tmp->map[i][j + 1] == 'C')
		{
			tmp->collectible--;
			tmp->map[i][j + 1] = tmp->map[i][j];
			tmp->map[i][j] = '0';
		}
		else
			change_pos(tmp, i, j, 2);
	}
	if (tmp->map[i][j + 1] == 'E' && tmp->collectible == 0)
	{
		change_pos(tmp, i, j, 2);
		draw_loop(tmp);
		mlx_destroy_image(tmp->mlx, tmp->img);
		mlx_clear_window(tmp->mlx, tmp->win);
		ft_printf("YOU WON\n");
		ft_printf("-------\n");
		exit(0);
	}
	draw_loop(tmp);
}

void	player_left(t_data *tmp, int i, int j)
{
	if (tmp->map[i][j - 1] != '1' && tmp->map[i][j - 1] != 'E')
	{
		++tmp->mv;
		if (tmp->map[i][j - 1] == 'C')
		{
			tmp->collectible--;
			tmp->map[i][j - 1] = tmp->map[i][j];
			tmp->map[i][j] = '0';
		}
		else
			change_pos(tmp, i, j, 3);
	}
	if (tmp->map[i][j - 1] == 'E' && tmp->collectible == 0)
	{
		change_pos(tmp, i, j, 3);
		draw_loop(tmp);
		mlx_destroy_image(tmp->mlx, tmp->img);
		mlx_clear_window(tmp->mlx, tmp->win);
		ft_printf("YOU WON\n");
		ft_printf("-------\n");
		exit(0);
	}
	draw_loop(tmp);
}
