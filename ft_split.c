/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afgoncal <massenaafonso1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:28:42 by afgoncal          #+#    #+#             */
/*   Updated: 2022/11/24 16:33:53 by afgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_words(char const *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i] != '\0')
			n++;
		while (str[i] != c && str[i])
			i++;
	}
	return (n);
}

int	word_len(char const *str, int c, int i)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		i;
	int		w;
	int		index;

	split = (char **)malloc(sizeof(char *) * ((num_words(str, c) + 1)));
	if (!split)
		return (0);
	i = 0;
	index = 0;
	while (str[i])
	{
		w = 0;
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i] != '\0')
			split[index] = (char *)malloc(sizeof(char)
					* (word_len(str, c, i) + 1));
		while (str[i] != c && str[i])
		{
			split[index][w] = str[i];
			i++;
			w++;
		}
		split[index][w] = '\0';
		index++;
	}
	split[index] = NULL;
	return (split);
}
