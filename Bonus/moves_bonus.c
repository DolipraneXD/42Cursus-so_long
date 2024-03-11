/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:31:17 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/27 16:03:14 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_door(t_image *img)
{
	mlx_put_image_to_window(img->mlx, img->window, img->img_f,
		img->door_x * 64, img->door_y * 64);
	mlx_put_image_to_window(img->mlx, img->window, img->img_eo,
		img->door_x * 64, img->door_y * 64);
}

void	print_player(t_image *img, int x, int y, int i)
{
	mlx_put_image_to_window(img->mlx, img->window, img->img_f,
		(img->map.p_x + x) * 64, (img->map.p_y + y) * 64);
	mlx_put_image_to_window(img->mlx, img->window, img->tab[i],
		(img->map.p_x + x) * 64, (img->map.p_y + y) * 64);
	mlx_put_image_to_window(img->mlx, img->window, img->img_f,
		img->map.p_x * 64, img->map.p_y * 64);
}

void	move(t_image *img, int x, int y, int i)
{
	if (img->map.p_y > 0 && img->map.p_y < img->map.m_h)
	{
		if (img->map.map[img->map.p_y + y][img->map.p_x + x] != '1')
		{
			if (img->map.map[img->map.p_y + y][img->map.p_x + x] == 'E' &&
					img->count_c == 0)
				you_win(img);
			else if (img->map.map[img->map.p_y + y][img->map.p_x + x] == 'X')
				you_lost(img);
			else if (img->map.map[img->map.p_y + y][img->map.p_x + x] == 'E' &&
					img->count_c != 0)
				return ;
			if (img->map.map[img->map.p_y + y][img->map.p_x + x] == 'C')
				img->count_c -= 1;
			if (img->count_c == 0)
				print_door(img);
			img->map.map[img->map.p_y + y][img->map.p_x + x] = 'P';
			print_player(img, x, y, i);
			img->map.map[img->map.p_y][img->map.p_x] = '0';
			img->map.p_y += y;
			img->map.p_x += x;
			img->count_move += 1;
		}
	}
}
