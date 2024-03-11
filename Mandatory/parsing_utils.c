/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:24:08 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/29 08:35:50 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_characters(char **str, char c)
{
	int	y;
	int	x;
	int	flag;

	y = 0;
	flag = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == c)
				flag++;
			x++;
		}
		y++;
	}
	return (flag);
}

int	check_flooded_map(char **map)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	len = ft_strlen(map[1]);
	while (map[y])
	{
		x = 0;
		while (x < len - 1)
		{
			if (map[y][x] != '1' && map[y][x] != 'F' && map[y][x] != '0')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	find_player_pos(t_image *img)
{
	int	y;
	int	x;

	y = 0;
	while (img->map.map[y])
	{
		x = 0;
		while (img->map.map[y][x])
		{
			if (img->map.map[y][x] == 'P')
			{
				img->map.p_y = y;
				img->map.p_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill_check(char ***map, int y, int x)
{
	if ((*map)[y][x] == 'E')
		(*map)[y][x] = 'F';
	if (map == NULL || (*map)[y] == NULL || (*map)[y][x] == '1'
			|| (*map)[y][x] == 'F' || x < 0 || y < 0)
		return ;
	(*map)[y][x] = 'F';
	flood_fill_check(map, y, x + 1);
	flood_fill_check(map, y, x - 1);
	flood_fill_check(map, y + 1, x);
	flood_fill_check(map, y - 1, x);
}

int	flood_fill(t_image *img)
{
	char	**map_dup;
	int		i;

	map_dup = (char **) malloc(sizeof(char *) * (img->map.m_h + 1));
	if (!map_dup)
		(perror("Error\n"), exit(1));
	i = 0;
	while (i < img->map.m_h)
	{
		map_dup[i] = ft_strdup(img->map.map[i]);
		i++;
	}
	map_dup[i] = NULL;
	find_player_pos(img);
	flood_fill_check(&map_dup, img->map.p_y, img->map.p_x);
	if (check_flooded_map(map_dup))
	{
		ft_free(map_dup);
		return (1);
	}
	ft_free(map_dup);
	return (0);
}
