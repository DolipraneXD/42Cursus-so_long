/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:29:55 by moel-fat          #+#    #+#             */
/*   Updated: 2024/03/05 10:27:06 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	assaing_value(t_image *image)
{
	image->player = "./Images/player.xpm";
	image->flor = "./Images/flor.xpm";
	image->wall = "./Images/wall.xpm";
	image->coin = "./daimond/daimond-1.xpm";
	image->exit = "./Images/exit.xpm";
	image->e_o = "./Images/exit_open.xpm";
	image->p_tab[0] = PLAYER1;
	image->p_tab[1] = PLAYER2;
	image->p_tab[2] = PLAYER3;
	image->p_tab[3] = PLAYER4;
	image->c_tab[0] = COIN1;
	image->c_tab[1] = COIN2;
	image->c_tab[2] = COIN3;
	image->c_tab[3] = COIN4;
	image->c_tab[4] = COIN5;
	image->c_tab[5] = COIN6;
	image->c_tab[6] = COIN7;
	image->c_tab[7] = COIN8;
	image->enemy[0] = ENEMY1;
	image->enemy[1] = ENEMY2;
	image->enemy[2] = ENEMY3;
	image->w = 64;
	image->h = 64;
	image->count_move = 0;
}

void	print_count(t_image *img)
{
	img->str = ft_itoa(img->count_move);
	mlx_put_image_to_window(img->mlx, img->window, img->img_w,
		0 * 64, 0 * 64);
	mlx_string_put(img->mlx, img->window, 25, 18, 0xffffffff, img->str);
	free(img->str);
}

int	key_press(int keycode, t_image *image)
{
	if (keycode == 126 || keycode == 13)
		move(image, 0, -1, 0);
	else if (keycode == 125 || keycode == 1)
		move(image, 0, 1, 1);
	else if (keycode == 124 || keycode == 2)
		move(image, 1, 0, 3);
	else if (keycode == 123 || keycode == 0)
		move(image, -1, 0, 2);
	else if (keycode == 53)
		exit_program(image);
	print_count(image);
	return (0);
}

void	make_image(t_image *image)
{
	image->mlx = mlx_init();
	image->count_c = count_characters(image->map.map, 'C');
	assaing_value(image);
	get_image_xpm(image);
	get_image_xpm1(image);
	get_image_xpm2(image);
	draw_image(image);
	mlx_hook(image->window, 2, 0, key_press, image);
	mlx_loop_hook(image->mlx, animation, image);
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
