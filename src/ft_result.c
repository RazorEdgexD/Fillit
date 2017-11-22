/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:02:19 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/20 16:06:59 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_clean(char **map, t_term *ptr, int max)
{
	int x;
	int y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (map[y][x] == ptr->letter)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

static char	**ft_fill_one(char **map, t_term *ptr, int max)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (ptr->x[i] == x && ptr->y[i] == y)
			{
				map[y][x] = ptr->letter;
				i++;
			}
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = NULL;
	return (map);
}

static int	ft_check(char **map, t_term *ptr, int max)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (ptr->x[i] == x && ptr->y[i] == y && map[y][x] != '.')
				return (0);
			else if (ptr->x[i] == x && ptr->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

static char	**ft_filling(char **map, t_term *ptr, int max)
{
	int		x;
	int		y;
	char	**tmp;

	if (!ptr->next)
		return (map);
	tmp = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			ptr = ft_new_xy_pos(ptr, x, y);
			if (ft_check(map, ptr, max))
				tmp = ft_filling(ft_fill_one(map, ptr, max), ptr->next, max);
			if (tmp)
				return (tmp);
			map = ft_clean(map, ptr, max);
			++x;
		}
		++y;
	}
	return (NULL);
}

char		**ft_result(t_term *ptr, int max)
{
	char **map;

	map = NULL;
	while (!map)
	{
		map = ft_create_map(max);
		map = ft_filling(map, ptr, max);
		max++;
	}
	return (map);
}
