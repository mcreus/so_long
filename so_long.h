/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:57:48 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/05 13:15:56 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft/libft.h"
# include "./libft/mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct s_image
{
	void	*img_coins;
	void	*img_wall;
	void	*img_exit;
	void	*img_player;
	void	*img_floor;
	int		hauteur;
	int		largeur;
	char	*coins;
	char	*wall;
	char	*exit;
	char	*player;
	char	*floor;
}				t_image;

typedef struct s_cont
{
	char	coins;
	char	wall;
	char	exit;
	char	player;
	char	floor;
	int		count_p;
	int		count_e;
	int		count_coins;
}				t_cont;

typedef struct s_pos
{
	int		x;
	int		y;
}		t_pos;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		largeur;
	int		hauteur;
	char	**map;
	t_cont	content;
	t_image	image;
	t_pos	pos;
	int		counter;
}				t_data;
/*
int		ft_strchr(char *str, char *cp);
void	*ft_error(char *str);
int		ft_same_char(char *str);

int		ft_same_char(char *str);
char	*get_map(int fd);
char	**map_core(char **str, t_data *data);
int		chk_map(char **argv);

int		ft_check_column(char *map_line, char col, t_data *data);
int		ft_check_line(char *map_line, char wall);
int		ft_check_other(char *map_line, t_cont *content);
void	ft_check_content(t_data *data);
int		ft_check_format(char **map);
int		check_coins(t_data *data;

void	put_img(t_data *data);
void	put_content(t_data *data);

void	map_create(t_data *data);
int		create(t_data *data);
void	create_other(t_data *data);
void	create_floor(t_data *data);
void	player_down(t_data *data);
void	player_left(t_data *data);
void	player_right(t_data *data);
void	player_top(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);

int		key_press(int keysym, t_data *data);
int		check_coins(t_data *data);
int		end(t_data *data);
*/
int		ft_strchr(char *str, char *cp);
int		check_coins(t_data *data);
void	create_floor(t_data *data);
void	create_other(t_data *data);
int		create(t_data *data);
void	map_create(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);
int		end(t_data *data);
int		key_press(int keysym, t_data *data);
int		main(int ac, char **av);
char	*get_map(int fd);
void	*ft_free_map(t_data *data);
char	**parse_map(int fd, t_data *data);
char	**map_core(char **str, t_data *data);
void	player_top(t_data *data);
void	player_right(t_data *data);
void	player_left(t_data *data);
void	player_down(t_data *data);
void	put_content(t_cont *content);
void	put_img(t_data *data);
int		ft_same_char(char *str);
void	*ft_error(char *str);
int		ft_check_column(char *map_line, char wall, t_data *data);
int		ft_check_line(char *map_line, char wall);
int		ft_check_other(char *map_line, t_cont *content);
void	ft_check_content(t_data *data);
int		ft_check_format(char **map);

#endif
