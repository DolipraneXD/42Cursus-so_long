/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:39:22 by moel-fat          #+#    #+#             */
/*   Updated: 2024/03/05 10:17:45 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\nEmpty Map", 2);
	else if (i == 2)
		ft_putstr_fd("Error\nInvalid Map", 2);
	else if (i == 3)
		ft_putstr_fd("Error\nNo Map Exists OR Invalid File Extension", 2);
	else if (i == 4)
		ft_putstr_fd("Error\nNeed The Map path as second arg", 2);
	exit (1);
}

int	exit_program(t_image *image)
{
	if (image->window != NULL)
		mlx_destroy_window(image->mlx, image->window);
	if (image->img_p != NULL)
		mlx_destroy_image(image->mlx, image->img_p);
	if (image->img_e != NULL)
		mlx_destroy_image(image->mlx, image->img_e);
	if (image->img_c != NULL)
		mlx_destroy_image(image->mlx, image->img_c);
	if (image->img_w != NULL)
		mlx_destroy_image(image->mlx, image->img_w);
	if (image->img_f != NULL)
		mlx_destroy_image(image->mlx, image->img_f);
	if (image->img_eo != NULL)
		mlx_destroy_image(image->mlx, image->img_eo);
	ft_free(image->map.map);
	free(image);
	exit (1);
}

void	you_win(t_image *img)
{
	ft_putstr_fd("YOU WIN !\n", 1);
	exit_program(img);
}
