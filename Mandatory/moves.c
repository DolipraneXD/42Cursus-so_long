/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:31:17 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/23 10:41:19 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_image *img)
{
	if (img->map.p_y > 0 && img->map.p_y < img->map.m_h)
	{
		if (img->map.map[img->map.p_y - 1][img->map.p_x] != '1')
		{
			if (img->map.map[img->map.p_y - 1][img->map.p_x] == 'E' &&
				img->count_c == 0)
				you_win(img);
			else if (img->map.map[img->map.p_y - 1][img->map.p_x] == 'E' &&
					img->count_c != 0)
				return ;
			if (img->map.map[img->map.p_y - 1][img->map.p_x] == 'C')
				img->count_c -= 1;
			img->map.map[img->map.p_y - 1][img->map.p_x] = 'P';
			img->map.map[img->map.p_y][img->map.p_x] = '0';
			img->map.p_y -= 1;
			img->count_move += 1;
			ft_printf("moves : %d\n", img->count_move);
		}
	}
}

void	move_down(t_image *img)
{
	if (img->map.p_y > 0 && img->map.p_y < img->map.m_h)
	{
		if (img->map.map[img->map.p_y + 1][img->map.p_x] != '1')
		{
			if (img->map.map[img->map.p_y + 1][img->map.p_x] == 'E' &&
				img->count_c == 0)
				you_win(img);
			else if (img->map.map[img->map.p_y + 1][img->map.p_x] == 'E' &&
					img->count_c != 0)
				return ;
			if (img->map.map[img->map.p_y + 1][img->map.p_x] == 'C')
				img->count_c -= 1;
			img->map.map[img->map.p_y + 1][img->map.p_x] = 'P';
			img->map.map[img->map.p_y][img->map.p_x] = '0';
			img->map.p_y += 1;
			img->count_move += 1;
			ft_printf("moves : %d\n", img->count_move);
		}
	}
}

void	move_left(t_image *img)
{
	if (img->map.p_x > 0 && img->map.p_x < img->map.m_l)
	{
		if (img->map.map[img->map.p_y][img->map.p_x - 1] != '1')
		{
			if (img->map.map[img->map.p_y][img->map.p_x - 1] == 'E' &&
				img->count_c == 0)
				you_win(img);
			else if (img->map.map[img->map.p_y][img->map.p_x - 1] == 'E' &&
					img->count_c != 0)
				return ;
			if (img->map.map[img->map.p_y][img->map.p_x - 1] == 'C')
				img->count_c -= 1;
			img->map.map[img->map.p_y][img->map.p_x - 1] = 'P';
			img->map.map[img->map.p_y][img->map.p_x] = '0';
			img->map.p_x -= 1;
			img->count_move += 1;
			ft_printf("moves : %d\n", img->count_move);
		}
	}
}

void	move_right(t_image *img)
{
	if (img->map.p_x > 0 && img->map.p_x < img->map.m_l)
	{
		if (img->map.map[img->map.p_y][img->map.p_x + 1] != '1')
		{
			if (img->map.map[img->map.p_y][img->map.p_x + 1] == 'E' &&
				img->count_c == 0)
				you_win(img);
			else if (img->map.map[img->map.p_y][img->map.p_x + 1] == 'E' &&
					img->count_c != 0)
				return ;
			if (img->map.map[img->map.p_y][img->map.p_x + 1] == 'C')
				img->count_c -= 1;
			img->map.map[img->map.p_y][img->map.p_x + 1] = 'P';
			img->map.map[img->map.p_y][img->map.p_x] = '0';
			img->map.p_x += 1;
			img->count_move += 1;
			ft_printf("moves : %d\n", img->count_move);
		}
	}
}
