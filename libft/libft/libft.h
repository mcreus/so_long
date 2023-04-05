/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:12:39 by arthur            #+#    #+#             */
/*   Updated: 2023/04/04 15:41:45 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

long long int	ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			**ft_split(char *str, char sep);
char			*ft_strdup(char *str);
size_t			ft_strlen(const char *str);
char			*ft_strncpy(char *str, int nb);
int				get_next_line(int fd, char **str);
char			*ft_strjoin(char *s1, char *s2);

#endif
