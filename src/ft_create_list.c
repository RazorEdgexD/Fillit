/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:03:59 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/20 16:04:01 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_str_in_list(t_term *ptr, char *str)
{
	int i;

	i = -1;
	if ((ptr->str = (char *)malloc(sizeof(char) * (TERM_SIZE))) == NULL)
		return ;
	while (++i < TERM_SIZE - 1)
	{
		ptr->str[i] = str[i];
	}
}

t_term			*ft_create_list(char *file)
{
	char	*buf;
	t_term	*lst;
	t_term	*ptr;
	char	letter;

	letter = 'A';
	if ((buf = ft_read_from_file(file)) == NULL)
		return (NULL);
	lst = (t_term *)malloc(sizeof(t_term));
	ptr = lst;
	while (*buf != '\0')
	{
		ft_str_in_list(ptr, buf);
		ptr->letter = letter;
		letter++;
		buf += 21;
		ptr->next = (t_term *)malloc(sizeof(t_term));
		ptr = ptr->next;
		ptr->next = NULL;
	}
	return (lst);
}
