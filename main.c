/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:02:34 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/05 13:37:55 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		mlx_destroy_image(data->mlx, data->image.img_wall);
		mlx_destroy_image(data->mlx, data->image.img_floor);
		mlx_destroy_image(data->mlx, data->image.img_coins);
		mlx_destroy_image(data->mlx, data->image.img_player);
		mlx_destroy_image(data->mlx, data->image.img_exit);
		mlx_destroy_window(data->mlx, data->win);
	}
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end(data);
	if (keysym == XK_w)
		player_top(data);
	if (keysym == XK_d)
		player_right(data);
	if (keysym == XK_a)
		player_left(data);
	if (keysym == XK_s)
		player_down(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_error("Error\nnot good numberof argc and .ber\n");
		return (0);
	}
	else
	{
		data.counter = 0;
		data.mlx = mlx_init();
		put_content(&(data.content));
		data.map = map_core(av, &data);
		if (data.map != NULL)
		{
			put_img(&data);
			map_create(&data);
		}
		else
			end(&data);
	}
	return (1);
}
