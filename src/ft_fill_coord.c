/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:59:03 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/20 16:00:06 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_term	*ft_position(char **arr, t_term *ptr)
{
	int		x;
	int		y;
	int		i;

	y = -1;
	i = 0;
	while (arr[++y])
	{
		x = 0;
		while (arr[y][x] != '\0')
		{
			if (arr[y][x] == '#')
			{
				ptr->x[i] = x;
				ptr->y[i] = y;
				i++;
			}
			x++;
		}
	}
	return (ptr);
}

t_term			*ft_fill_coord(t_term *ptr)
{
	t_term	*lst;

	lst = (t_term *)malloc(sizeof(t_term));
	lst = ptr;
	while (ptr->next)
	{
		ptr = ft_position(ft_strsplit(ptr->str, '\n'), ptr);
		ptr = ptr->next;
	}
	return (lst);
}
