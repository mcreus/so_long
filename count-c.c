/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count-c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:10:39 by mcreus            #+#    #+#             */
/*   Updated: 2023/03/30 16:14:34 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coins(t_data *data)
{
	int	i;
	int	y;
	int	count;

	i = 0;
	y = 0;
	count = 0;
	while (data->map[y])
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.coins)
				count++;
			i++;
		}
		i = 0;
		y++;
	}
	return (count);
}
