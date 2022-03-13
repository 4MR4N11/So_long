/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:18:25 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/13 15:18:48 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static	void	my_mlx_pixel_put(t_data *tmp, int color)
{
	char	*dst;

	tmp->offset = (tmp->y * tmp->ll + tmp->x * (tmp->bpp / 8));
	dst = tmp->addr + tmp->offset;
	*(unsigned int *)dst = color;
}

static	int	get_color(t_data *tmp, int i, int q)
{
	int	color;

	if (tmp->map[i][q] == '0')
		color = 0x007FD2E2;
	else if (tmp->map[i][q] == '1')
		color = 0x0004A1DB;
	else if (tmp->map[i][q] == 'C')
		color = 0x00D8AA76;
	else if (tmp->map[i][q] == 'P')
	{
		tmp->p_x = q;
		tmp->p_y = i;
		color = 0x0068C3B7;
	}
	else if (tmp->map[i][q] == 'E')
		color = 0x00F4F4F4;
	else
		color = 0;
	return (color);
}

void	put_square(t_data *tmp, int i, int q)
{
	int	tmp1;
	int	tmp2;
	int	color;

	tmp1 = tmp->x;
	tmp2 = tmp->y;
	color = get_color(tmp, i, q);
	while (tmp->y < tmp2 + 32)
	{
		while (tmp->x < tmp1 + 32)
		{
			if (color)
				my_mlx_pixel_put(tmp, color);
			tmp->x++;
		}
		tmp->x = tmp1;
		tmp->y++;
	}
	tmp->y = tmp2;
	tmp->x = tmp1 + 32;
}
