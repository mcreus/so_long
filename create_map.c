/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:36:26 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/05 13:40:03 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_floor(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->content.wall)
				print_img(data, data->image.img_wall, i, y);
			if (data->map[y][i] == data->content.floor)
				print_img(data, data->image.img_floor, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}

void	create_other(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.coins)
				print_img(data, data->image.img_coins, i, y);
			if (data->map[y][i] == data->content.player)
			{
				data->pos.x = i * data->image.largeur;
				data->pos.y = y * data->image.hauteur;
				print_img(data, data->image.img_player, i, y);
			}
			if (data->map[y][i] == data->content.exit)
				print_img(data, data->image.img_exit, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}

int	create(t_data *data)
{
	create_floor(data);
	create_other(data);
	return (0);
}

void	map_create(t_data *data)
{
	data->win = mlx_new_window(data->mlx,
			(data->largeur * data->image.largeur),
			(data->hauteur * data->image.hauteur), "so_long");
	if (data->win == NULL)
	{
		free(data->mlx);
		return ;
	}
	mlx_loop_hook(data->mlx, &create, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &key_press, data);
	mlx_hook(data->win, 17, 0, &end, data);
	mlx_loop(data->mlx);
	end(data);
}

void	print_img(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, image,
		data->image.largeur * x, data->image.hauteur * y);
}
