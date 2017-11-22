/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:00:41 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/20 16:00:58 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_error(char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_print_error();
	return (fd);
}

static char	*ft_check_double_n_and_blank(char *str, int i)
{
	char	*arr;

	arr = "Fail";
	if (str[i - 1] == '\n' && str[i - 2] == '\n')
		return (arr);
	if (str[i] == '\0' && i == 0)
		return (arr);
	return (str);
}

char		*ft_read_from_file(char *file)
{
	int		fd;
	char	*buf;
	int		size;
	int		handle;
	int		i;

	size = 0;
	i = 0;
	if ((fd = ft_error(file)) == -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * 1);
	while ((handle = read(fd, buf, 1) != 0))
		size += handle;
	close(fd);
	free(buf);
	buf = (char *)malloc(sizeof(char) * (size + 1));
	if ((fd = ft_error(file)) == -1)
		return (NULL);
	read(fd, buf, size);
	buf[size] = '\0';
	buf = ft_check_double_n_and_blank(buf, size);
	close(fd);
	return (buf);
}
