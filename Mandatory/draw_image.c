/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:15:26 by moel-fat          #+#    #+#             */
/*   Updated: 2024/03/09 11:10:48 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_image_xpm(t_image *img)
{
	img->window = mlx_new_window(img->mlx, (img->map.m_l - 1) * 64,
			img->map.m_h * 64, "so_long");
	if (!img->window)
		(perror("Error\n"), exit_program(img));
	img->img_p = mlx_xpm_file_to_image(img->mlx, img->player, &img->w, &img->h);
	if (!img->img_p)
		(perror("Error\n"), exit_program(img));
	img->img_f = mlx_xpm_file_to_image(img->mlx, img->flor, &img->w, &img->h);
	if (!img->img_f)
		(perror("Error\n"), exit_program(img));
	img->img_w = mlx_xpm_file_to_image(img->mlx, img->wall, &img->w, &img->h);
	if (!img->img_w)
		(perror("Error\n"), exit_program(img));
	img->img_c = mlx_xpm_file_to_image(img->mlx, img->coin, &img->w, &img->h);
	if (!img->img_c)
		(perror("Error\n"), exit_program(img));
	img->img_e = mlx_xpm_file_to_image(img->mlx, img->exit, &img->w, &img->h);
	if (!img->img_e)
		(perror("Error\n"), exit_program(img));
	img->img_eo = mlx_xpm_file_to_image(img->mlx, img->e_o, &img->w, &img->h);
	if (!img->img_eo)
		(perror("Error\n"), exit_program(img));
}

void	put_image(t_image *img, int y, int x)
{
	mlx_put_image_to_window(img->mlx, img->window, img->img_f,
		x * 64, y * 64);
	if (img->map.map[y][x] == '1')
		mlx_put_image_to_window(img->mlx, img->window, img->img_w,
			x * 64, y * 64);
	if (img->map.map[y][x] == 'P')
		mlx_put_image_to_window(img->mlx, img->window, img->img_p,
			x * 64, y * 64);
	if (img->map.map[y][x] == 'C')
		mlx_put_image_to_window(img->mlx, img->window, img->img_c,
			x * 64, y * 64);
	if (img->map.map[y][x] == 'E' && img->count_c != 0)
		mlx_put_image_to_window(img->mlx, img->window, img->img_e,
			x * 64, y * 64);
	if (img->map.map[y][x] == 'E' && img->count_c == 0)
		mlx_put_image_to_window(img->mlx, img->window, img->img_eo,
			x * 64, y * 64);
}

void	draw_image(t_image *img)
{
	int	x;
	int	y;

	y = 0;
	while (img->map.map[y])
	{
		x = 0;
		while (x < img->map.m_l - 1)
		{
			put_image(img, y, x);
			x++;
		}
		y++;
	}
}
