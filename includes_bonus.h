/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrani <amrani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:15:29 by kel-amra          #+#    #+#             */
/*   Updated: 2023/01/25 13:43:10 by amrani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef INCLUDES_BONUS_H
# define INCLUDES_BONUS_H

# include <fcntl.h>
# include "mlx_linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

typedef struct s_data
{
	int		msg;
	int		fd;
	int		fd_tmp;
	int		player_color;
	int		ll;
	int		mv;
	int		lines;
	int		enemy;
	int		emty_space;
	int		h;
	int		w;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		offset;
	int		collectible;
	int		wall_num;
	int		map_exit;
	int		p_start_position;
	char	**map;
	int		bpp;
	void	*win;
	void	*mlx;
	char	*addr;
	void	*img;
	int		endi;
}	t_data;

char	*ft_itoa(int n);
void	change_pos(t_data *tmp, int i, int j, int index);
int		close_window(t_data *tmp);
void	put_square(t_data *tmp, int i, int q);
int		get_event(int keycode, t_data *tmp);
int		walls_checker(char *str);
int		free_data(char **str);
int		map_component(char *str, t_data *tmp);
int		map_component_checker(t_data *tmp);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	initialisation(t_data *tmp);
void	draw(t_data *tmp);
int		map_extension_checker(char *map);
int		errors_check(int ac, t_data *tmp, char *str);
int		parsing(t_data *tmp);
int		line_counter(int fd_tmp);
void	player_up(t_data *tmp, int i, int j);
void	player_down(t_data *tmp, int i, int j);
void	player_right(t_data *tmp, int i, int j);
void	player_left(t_data *tmp, int i, int j);
void	drawer(t_data *tmp);
#	endif