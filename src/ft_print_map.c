/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:09:56 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/15 19:28:39 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(char **map)
{
	int i;

	i = -1;
	while (map[++i] != '\0')
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}
