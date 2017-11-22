/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 22:13:45 by akoshyna          #+#    #+#             */
/*   Updated: 2016/11/27 14:41:09 by akoshyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
	return (n);
}

static int	count_let(char const *s, char c, int i)
{
	int n;

	n = 0;
	while (s[i] != c && s[i])
	{
		i++;
		n++;
	}
	return (n);
}

static char	*put_word(char const *s, char c, int *i)
{
	char	*word;
	int		j;

	word = (char *)malloc(sizeof(char) * (count_let(s, c, *i) + 1));
	if (word)
	{
		j = 0;
		while (s[*i] != c && s[*i])
		{
			word[j] = s[*i];
			(*i)++;
			j++;
		}
		word[j] = '\0';
		return (word);
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	if (!(s && c))
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = put_word(s, c, &i);
			if (!arr[j])
				return (NULL);
			j++;
		}
		else
			i++;
	}
	arr[j] = 0;
	return (arr);
}
