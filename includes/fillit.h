/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:21:09 by aosobliv          #+#    #+#             */
/*   Updated: 2016/12/20 16:09:08 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
# define TERM_SIZE 21

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct			s_term
{
	char				letter;
	char				*str;
	int					x[4];
	int					y[4];
	struct s_term		*next;
}						t_term;

void					ft_putchar(char c);
void					ft_putstr(char const *s);
char					**ft_strsplit(char const *s, char c);
int						ft_general_valid(char *file);
char					**ft_create_map(int size);
char					*ft_read_from_file(char *file);
void					ft_print_error(void);
t_term					*ft_fill_coord(t_term *ptr);
t_term					*ft_create_list(char *file);
int						ft_len_list(t_term *ptr);
t_term					*ft_new_xy_pos(t_term *ptr, int x, int y);
void					ft_print_map(char **map);
char					**ft_result(t_term *ptr, int max);

#endif
