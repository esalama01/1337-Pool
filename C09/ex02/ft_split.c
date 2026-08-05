/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:21:39 by elsalama          #+#    #+#             */
/*   Updated: 2026/08/04 14:22:49 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int	calc_size(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		while (is_charset(str[i], charset))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
	}
	return (count);
}

int	allocation_size(char *str, char *charset, int i)
{
	int	j;

	j = 0;
	while (str[i + j] && !is_charset(str[i + j], charset))
		j++;
	return (j);
}

char	**fill_array(char **arr, char *str, char *charset)
{
	int	k;
	int	j;

	k = 0;
	while (*str)
	{
		while (is_charset(*str, charset))
			str++;
		if (!*str)
			break ;
		j = 0;
		arr[k] = (char *)malloc(allocation_size(str, charset, 0) + 1);
		if (!arr[k])
			return (NULL);
		while (*str && !is_charset(*str, charset))
		{
			arr[k][j] = *str;
			str++;
			j++;
		}
		arr[k][j] = '\0';
		k++;
	}
	arr[k] = NULL;
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**arr;

	size = calc_size(str, charset);
	arr = (char **)malloc((size + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (str[0] == '\0')
	{
		arr[0] = NULL;
		return (arr);
	}
	arr = fill_array(arr, str, charset);
	if (!arr)
		return (NULL);
	return (arr);
}
