/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 18:37:24 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/17 18:37:26 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_len_list(t_term *ptr)
{
	int count_term;
	int size;

	count_term = 0;
	size = 1;
	while (ptr->next)
	{
		count_term++;
		ptr = ptr->next;
	}
	while ((size * size) < (count_term * 4))
	{
		size++;
	}
	return (size);
}
