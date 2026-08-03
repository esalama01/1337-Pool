/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:39:08 by elsalama          #+#    #+#             */
/*   Updated: 2026/08/02 20:42:34 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	get_full_size(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	l_sep;
	int	l_strs;
	int	full_size;

	i = 0;
	l_strs = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			l_strs++;
			j++;
		}
		i++;
	}
	l_sep = 0;
	while (sep[l_sep])
		l_sep++;
	full_size = (l_sep * (size - 1)) + l_strs;
	return (full_size);
}

char	*create_str(int size, char **strs, char *sep)
{
	int		full_size;
	char	*str;

	full_size = get_full_size(size, strs, sep);
	str = (char *)malloc(full_size + 1);
	if (!str)
		return (NULL);
	return (str);
}

void	fill_string(char *str, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[l] = strs[i][j];
			l++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			str[l] = sep[j];
			l++;
			j++;
		}
		i++;
	}
	str[get_full_size(size, strs, sep)] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;

	if (size == 0)
	{
		str = malloc(1);
		if (str)
			str[0] = '\0';
		return (str);
	}
	str = create_str(size, strs, sep);
	if (!str)
		return (NULL);
	fill_string(str, size, strs, sep);
	return (str);
}
