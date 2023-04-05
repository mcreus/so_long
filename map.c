/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:27:00 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/05 13:55:47 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_map(int fd)
{
	char	*line;
	char	*buffer;
	int		char_count;
	char	*tmp_buffer;

	line = ft_strdup("");
	buffer = ft_strdup("");
	char_count = get_next_line(fd, &line);
	if (char_count > 0)
	{
		tmp_buffer = buffer;
		while (char_count > 0)
		{
			buffer = ft_strjoin(buffer, line);
			free(tmp_buffer);
			free(line);
			line = ft_strdup("");
			char_count = get_next_line(fd, &line);
			tmp_buffer = buffer;
		}
		return (buffer);
	}
	ft_error("Error Wrong lecture map\n");
	return (NULL);
}

void	*ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

char	**parse_map(int fd, t_data *data)
{
	int	i;

	i = 1;
	data->map = ft_split(get_map(fd), '\n');
	ft_check_content(data);
	if (!(ft_check_format(data->map)))
		return (ft_free_map(data));
	if (!(ft_check_line(data->map[0], data->content.wall)))
		return (ft_free_map(data));
	while (data->map[i])
	{
		if (!(ft_check_column(data->map[i], data->content.wall, data)))
			return (ft_free_map(data));
		else if (!(ft_check_other(data->map[i], &(data->content))))
			return (ft_free_map(data));
		i++;
	}
	data->hauteur = i;
	if (!(ft_check_line(data->map[i - 1], data->content.wall)))
		return (ft_free_map(data));
	return (data->map);
}

char	**map_core(char **str, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchr(str[1], ".ber") == 0)
		return (ft_error("Error format no correct\n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = parse_map(fd, data);
		else
			return (ft_error("Error, impossible open\n"));
		if ((data->content.count_coins == 0 || data->content.count_e != 1
				|| data->content.count_p != 1) && data->map != NULL)
		{
			ft_free_map(data);
			return (ft_error("Error player and exit\n"));
		}
	}
	return (data->map);
}
