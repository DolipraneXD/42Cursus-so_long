/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:24:03 by moel-fat          #+#    #+#             */
/*   Updated: 2024/03/09 11:14:24 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_elements(t_image img)
{
	if (count_characters(img.map.map, 'E') != 1)
		return (1);
	else if (count_characters(img.map.map, 'P') != 1)
		return (1);
	else if (count_characters(img.map.map, 'C') < 1)
		return (1);
	return (0);
}

int	check_valid_map(t_image img)
{
	int	y;
	int	x;

	y = 0;
	while (img.map.map[y])
	{
		x = 0;
		while (x < img.map.m_l - 1)
		{
			if (img.map.map[0][x] != '1' ||
				img.map.map[img.map.m_h - 1][x] != '1')
				return (1);
			else if (img.map.map[y][0] != '1' ||
					img.map.map[y][img.map.m_l - 2] != '1')
				return (1);
			else if (img.map.map[y][x] != '1' && img.map.map[y][x] != 'P'
					&& img.map.map[y][x] != 'E' && img.map.map[y][x] != 'C'
					&& img.map.map[y][x] != '0')
				return (1);
			else
				x++;
		}
		y++;
	}
	return (0);
}

char	**read_map(int fd, char *file_name, t_image *img)
{
	char	**map;
	char	*line;
	int		i;

	(1) && (i = -1, img->map.m_h = 0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		img->map.m_h++;
		free(line);
	}
	if (img->map.m_h == 0)
		(close (fd), ft_error(1));
	map = (char **) malloc(sizeof(char *) * (img->map.m_h + 1));
	if (!map)
		(perror("Error\n"), close (fd), exit(1));
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		(perror("Error\n"), exit(1));
	ft_read(img, &map, fd);
	close(fd);
	return (map);
}

int	check_map_exists(char *file_name)
{
	int	fd;
	int	len;

	len = ft_strlen(file_name);
	if ((len < 4) || ft_strnstr(&file_name[len - 4], ".ber", len) == NULL)
		ft_error(3);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error(3);
	return (fd);
}

void	check_read_map(char *av, t_image *img)
{
	int	fd;

	fd = check_map_exists(av);
	img->map.map = read_map(fd, av, img);
	img->map.m_l = ft_strlen(img->map.map[0]);
	if (checklen(*img))
		ft_error(2);
	if (check_valid_map(*img))
		ft_error(2);
	if (check_elements(*img))
		ft_error(2);
	if (flood_fill(img))
		ft_error(2);
}
