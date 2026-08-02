/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:36:54 by elsalama          #+#    #+#             */
/*   Updated: 2026/08/01 18:24:38 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*ret;

	i = ft_strlen(src);
	ret = (char *)malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	fill_struct(t_stock_str *stocks, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		stocks[i].size = ft_strlen(av[i]);
		stocks[i].str = av[i];
		stocks[i].copy = ft_strdup(av[i]);
		if (!stocks[i].copy)
		{
			j = 0;
			while (j < i)
			{
				free(stocks[j].copy);
				j++;
			}
			free(stocks);
			return (0);
		}
		i++;
	}
	stocks[i].str = 0;
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stocks;

	stocks = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!stocks)
		return (NULL);
	if (!fill_struct(stocks, ac, av))
		return (NULL);
	return (stocks);
}
