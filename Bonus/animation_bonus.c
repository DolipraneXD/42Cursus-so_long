/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:04:57 by moel-fat          #+#    #+#             */
/*   Updated: 2024/03/09 14:26:43 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	anime_coin(t_image *img, int i)
{
	int	y;
	int	x;

	y = 0;
	while (img->map.map[y])
	{
		x = 0;
		while (x < img->map.m_l)
		{
			if (img->map.map[y][x] == 'C')
			{
				mlx_put_image_to_window(img->mlx, img->window, img->ctab[i],
					x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	anime_enemy(t_image *img, int i)
{
	int	y;
	int	x;

	y = 0;
	while (img->map.map[y])
	{
		x = 0;
		while (x < img->map.m_l)
		{
			if (img->map.map[y][x] == 'X')
			{
				mlx_put_image_to_window(img->mlx, img->window, img->img_f,
					x * 64, y * 64);
				mlx_put_image_to_window(img->mlx, img->window, img->etab[i],
					x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

int	animation(t_image *img)
{
	static int	i;
	static int	j;
	static int	m;
	static int	k;

	if (j == 800)
	{
		anime_coin(img, i);
		j = 0;
		i++;
		if (i == 8)
			i = 0;
	}
	j++;
	if (m == 2000)
	{
		anime_enemy(img, k);
		m = 0;
		k++;
		if (k == 3)
			k = 0;
	}
	m++;
	return (0);
}
