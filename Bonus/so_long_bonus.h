/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 08:52:27 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/29 10:40:44 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <libc.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# define PLAYER1 "./Images/player1.xpm"
# define PLAYER2 "./Images/player2.xpm"
# define PLAYER3 "./Images/player3.xpm"
# define PLAYER4 "./Images/player4.xpm"
# define COIN1 "./daimond/daimond-1.xpm"
# define COIN2 "./daimond/daimond-2.xpm"
# define COIN3 "./daimond/daimond-3.xpm"
# define COIN4 "./daimond/daimond-4.xpm"
# define COIN5 "./daimond/daimond-5.xpm"
# define COIN6 "./daimond/daimond-6.xpm"
# define COIN7 "./daimond/daimond-7.xpm"
# define COIN8 "./daimond/daimond-8.xpm"
# define ENEMY1 "./Images/bat1.xpm"
# define ENEMY2 "./Images/bat2.xpm"
# define ENEMY3 "./Images/bat3.xpm"
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
	char	*p_tab[4];
	char	*c_tab[8];
	char	*enemy[4];
	void	*tab[4];
	void	*etab[4];
	void	*ctab[8];
	char	*flor;
	char	*wall;
	char	*coin;
	char	*exit;
	char	*str;
	void	*e_o;
	int		w;
	int		h;
	int		count_c;
	int		door_x;
	int		door_y;
	int		count_move;
	int		c_y;
	int		c_x;
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
void	you_lost(t_image *img);
//**moves**//
void	move(t_image *img, int x, int y, int i);
//**animation**//
void	anime_coin(t_image *img, int i);
void	anime_enemy(t_image *img, int i);
int		animation(t_image *img);
//**mlx**//
void	get_image_xpm(t_image *img);
void	get_image_xpm1(t_image *img);
void	get_image_xpm2(t_image *img);
void	put_image(t_image *img, int y, int x);
void	draw_image(t_image *img);
//**utils**//
void	assaing_value(t_image *image);
#endif