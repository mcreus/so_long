/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:43:35 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/05 13:33:09 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_column(char *map_line, char wall, t_data *data)
{
	int	i;

	i = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
		ft_error("Error columns \n");
		return (0);
	}
	data->largeur = i;
	return (1);
}

int	ft_check_line(char *map_line, char wall)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != wall)
		{
			ft_error("Error line walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_other(char *map_line, t_cont *content)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (content->count_e > 1 || content->count_p > 1)
		{
			ft_error("Error\n not authorized player and exit\n");
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->player
			&& map_line[i] != content->exit
			&& map_line[i] != content->coins
			&& map_line[i] != content->floor)
		{
			ft_error("Error not good symbol on map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_check_content(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		while (data->map[i][y])
		{
			if (data->map[i][y] == data->content.coins)
				data->content.count_coins += 1;
			if (data->map[i][y] == data->content.player)
				data->content.count_p += 1;
			if (data->map[i][y] == data->content.exit)
				data->content.count_e += 1;
			y++;
		}
		y = 0;
		i++;
	}
}

int	ft_check_format(char **map)
{
	int	y;
	int	x;
	int	count_x;

	y = 0;
	x = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != count_x)
		{
			ft_error("Error map not rectangular\n");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}
