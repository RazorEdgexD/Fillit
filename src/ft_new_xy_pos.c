/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_xy_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:21:33 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/20 16:05:42 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_term		*ft_new_xy_pos(t_term *ptr, int x, int y)
{
	int		min_x;
	int		min_y;
	int		i;

	i = 0;
	min_x = 7;
	min_y = 7;
	while (i != 4)
	{
		if (ptr->x[i] < min_x)
			min_x = ptr->x[i];
		if (ptr->y[i] < min_y)
			min_y = ptr->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		ptr->x[i] = ptr->x[i] - min_x + x;
		ptr->y[i] = ptr->y[i] - min_y + y;
		i++;
	}
	return (ptr);
}
