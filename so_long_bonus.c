/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:08:16 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/13 19:42:00 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus.h"

void	initialisation(t_data *tmp)
{
	tmp->img = mlx_new_image(tmp->mlx, ((tmp->w - 1) * 32), (tmp->h * 32));
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bpp, &tmp->ll, &tmp->endi);
}

int	line_counter(int fd_tmp)
{
	char	*str;
	int		lines;

	lines = 0;
	str = get_next_line(fd_tmp);
	while (str)
	{
		lines++;
		free (str);
		str = NULL;
		str = get_next_line(fd_tmp);
	}
	return (lines);
}

int	main(int ac, char **av)
{
	t_data	tmp;

	tmp.mlx = mlx_init();
	tmp.emty_space = 0;
	tmp.collectible = 0;
	tmp.p_start_position = 0;
	tmp.enemy = 0;
	tmp.map_exit = 0;
	tmp.map = NULL;
	if (errors_check(ac, &tmp, av[1]))
		return (2);
	tmp.win = mlx_new_window(tmp.mlx, (tmp.w - 1) * 32, tmp.h * 32, "So_long");
	close(tmp.fd);
	draw(&tmp);
	return (0);
}
