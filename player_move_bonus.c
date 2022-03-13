/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:17:03 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/13 20:18:38 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus.h"

static	void	draw_loop(t_data *tmp, int check)
{
	if (check == 0)
	{
		mlx_destroy_image(tmp->mlx, tmp->img);
		initialisation(tmp);
		drawer(tmp);
		mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img, 0, 0);
	}
	else if (check == 1)
	{
		mlx_destroy_image(tmp->mlx, tmp->img);
		mlx_clear_window(tmp->mlx, tmp->win);
		ft_printf("YOU WON\n");
		ft_printf("-------\n");
		exit(0);
	}
	else
	{
		mlx_destroy_image(tmp->mlx, tmp->img);
		mlx_clear_window(tmp->mlx, tmp->win);
		ft_printf("YOU LOSE\n");
		ft_printf("--------\n");
		exit(0);
	}
}

void	player_up(t_data *tmp, int i, int j)
{
	if (tmp->map[i -1][j] == '0' || tmp->map[i -1][j] == 'C')
	{
		tmp->player_color = 0x00A8DCD9;
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
		tmp->player_color = 0x00A8DCD9;
		change_pos(tmp, i, j, 0);
		draw_loop(tmp, 1);
	}
	if (tmp->map[i - 1][j] == 'X')
	{
		change_pos(tmp, i, j, 0);
		draw_loop(tmp, 2);
	}
	draw_loop(tmp, 0);
}

void	player_down(t_data *tmp, int i, int j)
{
	if (tmp->map[i +1][j] == '0' || tmp->map[i +1][j] == 'C')
	{
		tmp->player_color = 0x00CCEAE8;
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
		tmp->player_color = 0x00CCEAE8;
		change_pos(tmp, i, j, 1);
		draw_loop(tmp, 1);
	}
	if (tmp->map[i + 1][j] == 'X')
	{
		change_pos(tmp, i, j, 1);
		draw_loop(tmp, 2);
	}
	draw_loop(tmp, 0);
}

void	player_right(t_data *tmp, int i, int j)
{
	if (tmp->map[i][j +1] == '0' || tmp->map[i][j +1] == 'C')
	{
		tmp->player_color = 0x0068C3B7;
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
		tmp->player_color = 0x0068C3B7;
		change_pos(tmp, i, j, 2);
		draw_loop(tmp, 1);
	}
	if (tmp->map[i][j +1] == 'X')
	{
		change_pos(tmp, i, j, 2);
		draw_loop(tmp, 2);
	}
	draw_loop(tmp, 0);
}

void	player_left(t_data *tmp, int i, int j)
{
	if (tmp->map[i][j -1] == '0' || tmp->map[i][j -1] == 'C')
	{
		tmp->player_color = 0x00539091;
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
		tmp->player_color = 0x00539091;
		change_pos(tmp, i, j, 3);
		draw_loop(tmp, 1);
	}
	if (tmp->map[i][j -1] == 'X')
	{
		change_pos(tmp, i, j, 3);
		draw_loop(tmp, 2);
	}
	draw_loop(tmp, 0);
}
