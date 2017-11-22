/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:01:46 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/20 16:01:48 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_n_true(char *str)
{
	int i;
	int n;

	i = 4;
	n = 4;
	while (n != 0)
	{
		if (str[i] != '\n')
		{
			return (0);
		}
		i += 5;
		n--;
	}
	return (1);
}

static int	ft_check_and_count(char *str)
{
	int i;
	int count_grate;
	int count_n;
	int count_point;

	i = 0;
	count_n = 0;
	count_point = 0;
	count_grate = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			count_point++;
		if (str[i] == '#')
			count_grate++;
		if (str[i] == '\n')
			count_n++;
		i++;
	}
	if (count_n == 4 && count_grate == 4 && count_point == 12)
		return (1);
	return (0);
}

static int	ft_figure_valid(char *str)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				count++;
			if (str[i + 5] == '#')
				count++;
		}
	}
	if (count == 3 || count == 4)
		return (1);
	return (0);
}

int			ft_general_valid(char *file)
{
	char	*arr;
	char	**term;
	int		i;
	int		nine;

	nine = 20;
	i = -1;
	arr = ft_read_from_file(file);
	while (arr[nine] == '\n')
	{
		arr[nine] = 27;
		nine += 21;
	}
	term = ft_strsplit(arr, 27);
	while (term[++i] != '\0')
	{
		if (!(ft_n_true(term[i])))
			return (0);
		if (!(ft_check_and_count(term[i])))
			return (0);
		if (!(ft_figure_valid(term[i])))
			return (0);
	}
	return (1);
}
