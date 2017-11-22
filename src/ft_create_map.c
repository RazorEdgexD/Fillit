/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 18:37:34 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/20 16:01:20 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(int size)
{
	char	**map;
	int		n;
	int		j;

	n = size;
	map = (char **)malloc(sizeof(char *) * (n + 1));
	map[n] = NULL;
	while (--n >= 0)
	{
		map[n] = (char *)malloc(sizeof(char) * (size + 1));
		j = size;
		map[n][j] = '\0';
		while (--j >= 0)
			map[n][j] = '.';
	}
	return (map);
}
