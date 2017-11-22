/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:50:09 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/20 16:07:36 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_term	*ptr;

	if (argc == 2)
	{
		if (!(ft_general_valid(argv[1])))
		{
			ft_print_error();
			return (0);
		}
		ptr = ft_fill_coord(ft_create_list(argv[1]));
		ft_print_map(ft_result(ptr, ft_len_list(ptr)));
	}
	else
		ft_print_error();
	return (0);
}
