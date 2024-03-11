/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:29:55 by moel-fat          #+#    #+#             */
/*   Updated: 2024/03/05 10:21:57 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assaing_value(t_image *image)
{
	image->player = "./Images/player.xpm";
	image->flor = "./Images/flor.xpm";
	image->wall = "./Images/wall.xpm";
	image->coin = "./Images/daim1.xpm";
	image->exit = "./Images/exit.xpm";
	image->e_o = "./Images/exit_open.xpm";
	image->w = 64;
	image->h = 64;
	image->count_move = 0;
}

int	key_press(int keycode, t_image *image)
{
	if (keycode == 126 || keycode == 13)
		move_up(image);
	else if (keycode == 125 || keycode == 1)
		move_down(image);
	else if (keycode == 124 || keycode == 2)
		move_right(image);
	else if (keycode == 123 || keycode == 0)
		move_left(image);
	else if (keycode == 53)
		exit_program(image);
	mlx_clear_window(image->mlx, image->window);
	draw_image(image);
	return (0);
}

void	make_image(t_image *image)
{
	image->mlx = mlx_init();
	image->count_c = count_characters(image->map.map, 'C');
	assaing_value(image);
	get_image_xpm(image);
	draw_image(image);
	mlx_hook(image->window, 2, 0, key_press, image);
	mlx_hook(image->window, 17, 0L, exit_program, image);
	mlx_loop(image->mlx);
}

int	main(int ac, char **av)
{
	t_image	*image;

	if (ac != 2)
		ft_error(4);
	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (1);
	check_read_map(av[1], image);
	make_image(image);
	ft_free(image->map.map);
	free(image);
}
