/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 08:52:27 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/29 11:38:14 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <libc.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# define MAX_L 40
# define MAX_H 21

// **map struct**
typedef struct s_map
{
	int		p_y;
	int		p_x;
	int		m_h;
	int		m_l;
	char	**map;
}			t_map;

typedef struct s_image
{
	void	*mlx;
	void	*window;
	void	*img_p;
	void	*img_f;
	void	*img_w;
	void	*img_c;
	void	*img_e;
	void	*img_eo;
	char	*player;
	char	*flor;
	char	*wall;
	char	*coin;
	char	*exit;
	void	*e_o;
	int		w;
	int		h;
	int		count_c;
	int		count_move;
	t_map	map;
}			t_image;

//**parsing**//
void	check_read_map(char *av, t_image *img);
int		count_characters(char **str, char c);
int		flood_fill(t_image *img);
int		checklen(t_image img);
size_t	check_line_len(const char *str);
void	ft_read(t_image *img, char ***map, int fd);
//**error handling**//
void	ft_free(char **str);
void	ft_error(int i);
int		exit_program(t_image *image);
void	you_win(t_image *img);
//**moves**//
void	move_up(t_image *image);
void	move_down(t_image *image);
void	move_left(t_image *image);
void	move_right(t_image *image);
//**mlx**//
void	get_image_xpm(t_image *img);
void	put_image(t_image *img, int y, int x);
void	draw_image(t_image *img);
//**utils**//
void	assaing_value(t_image *image);
#endif