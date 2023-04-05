/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:50:20 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/03 14:32:19 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_same_char(char *str)
{
	int		i;
	char	buffer;

	i = 0;
	buffer = '1';
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] != buffer && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

int	ft_strchr(char *str, char *cp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!cp[i] && !str[i])
		return (1);
	while (str[i])
	{
		while (str[i + j] == cp[j] && str[i + j] && cp[j])
			j++;
		if (!cp[j] && !str[i + j])
			return (1);
		else
			j = 0;
		i++;
	}
	return (0);
}
