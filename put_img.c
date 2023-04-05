/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:06:10 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/05 11:22:59 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_content(t_cont *content)
{
	content->coins = 'C';
	content->wall = '1';
	content->exit = 'E';
	content->player = 'P';
	content->floor = '0';
	content->count_p = 0;
	content->count_e = 0;
	content->count_coins = 0;
}

void	put_img(t_data *data)
{
	data->image.largeur = 50;
	data->image.hauteur = 50;
	data->image.coins = "./textures/coins.xpm";
	data->image.wall = "./textures/mur.xpm";
	data->image.exit = "./textures/sortie.xpm";
	data->image.player = "./textures/mouvement_droite.xpm";
	data->image.floor = "./textures/fond_noir.xpm";
	data->image.img_coins = mlx_xpm_file_to_image(data->mlx, data->image.coins,
			&(data->image.largeur), &(data->image.hauteur));
	data->image.img_wall = mlx_xpm_file_to_image(data->mlx, data->image.wall,
			&(data->image.largeur), &(data->image.hauteur));
	data->image.img_exit = mlx_xpm_file_to_image(data->mlx, data->image.exit,
			&(data->image.largeur), &(data->image.hauteur));
	data->image.img_player = mlx_xpm_file_to_image(data->mlx,
			data->image.player,
			&(data->image.largeur), &(data->image.hauteur));
	data->image.img_floor = mlx_xpm_file_to_image(data->mlx, data->image.floor,
			&(data->image.largeur), &(data->image.hauteur));
}
