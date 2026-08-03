/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 12:26:36 by elsalama          #+#    #+#             */
/*   Updated: 2026/08/03 13:07:40 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_putnbr_base(int nbr, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

int	in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (!check_base(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (in_base(str[i], base) != -1)
	{
		result *= ft_strlen(base);
		result += in_base(str[i], base);
		i++;
	}
	return (result * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbrr;
	char	*str;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	nbrr = ft_atoi_base(nbr, base_from);
	str = ft_putnbr_base(nbrr, base_to);
	return (str);
}
