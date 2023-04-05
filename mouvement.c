/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:03:38 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/05 11:20:33 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_top(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->image.largeur;
	pos_y = data->pos.y / data->image.hauteur;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.floor;
			data->counter += 1;
			printf("count: %d\n", data->counter);
		}
		else
		{
			if (check_coins(data) == 0)
			{
				printf("FELICITATIONS, vous gagnez en : %d coups!\n",
					data->counter);
				end(data);
			}
		}
	}
}

void	player_right(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->image.largeur;
	pos_y = data->pos.y / data->image.hauteur;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.floor;
			data->counter += 1;
			printf("count: %d\n", data->counter);
		}
		else
		{
			if (check_coins(data) == 0)
			{
				printf("FELICITATIONS vous gagnez en : %d coups !\n",
					data->counter);
				end(data);
			}
		}
	}
}

void	player_left(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->image.largeur;
	pos_y = data->pos.y / data->image.hauteur;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.floor;
			data->counter += 1;
			printf("count: %d\n", data->counter);
		}
		else
		{
			if (check_coins(data) == 0)
			{
				printf("FELICITATIONS vous gagnez en : %d coups!\n",
					data->counter);
				end(data);
			}
		}
	}
}

void	player_down(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->image.largeur;
	pos_y = data->pos.y / data->image.hauteur;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.floor;
			data->counter += 1;
			printf("count: %d\n", data->counter);
		}
		else
		{
			if (check_coins(data) == 0)
			{
				printf("FELICITATIONS vous gagnez en : %d coups!\n",
					data->counter);
				end(data);
			}
		}
	}
}
