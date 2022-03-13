/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_position_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:53:20 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/13 15:04:03 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus.h"

static	void	up_down(t_data *tmp, int i, int j, int index)
{
	char	c;

	if (index == 0)
	{
		c = tmp->map[i][j];
		tmp->map[i][j] = tmp->map[i - 1][j];
		tmp->map[i - 1][j] = c;
	}
	else
	{
		c = tmp->map[i][j];
		tmp->map[i][j] = tmp->map[i + 1][j];
		tmp->map[i + 1][j] = c;
	}
}

static	void	right_left(t_data *tmp, int i, int j, int index)
{
	char	c;

	if (index == 2)
	{
		c = tmp->map[i][j];
		tmp->map[i][j] = tmp->map[i][j +1];
		tmp->map[i][j + 1] = c;
	}
	else
	{
		c = tmp->map[i][j];
		tmp->map[i][j] = tmp->map[i][j -1];
		tmp->map[i][j - 1] = c;
	}
}

void	change_pos(t_data *tmp, int i, int j, int index)
{
	if (index == 0 || index == 1)
		up_down(tmp, i, j, index);
	else
		right_left(tmp, i, j, index);
}
