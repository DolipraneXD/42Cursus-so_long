/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:15:50 by moel-fat          #+#    #+#             */
/*   Updated: 2024/03/09 11:21:24 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	check_line_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	checklen(t_image img)
{
	int		i;
	size_t	len;

	i = 0;
	len = check_line_len(img.map.map[i]);
	while (img.map.map[i])
	{
		if (check_line_len(img.map.map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

void	ft_read(t_image *img, char ***map, int fd)
{
	int	i;

	i = 0;
	while (i < img->map.m_h)
	{
		(*map)[i] = get_next_line(fd);
		if (!(*map)[i])
			break ;
		i++;
	}
	(*map)[i] = NULL;
}
