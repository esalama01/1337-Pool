/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:39:38 by elsalama          #+#    #+#             */
/*   Updated: 2026/08/03 13:07:57 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_base2(char *base)
{
	int	i;
	int	j;

	if (ft_strlen2(base) <= 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

char	*create_str(int nbr, char *base)
{
	int			full_size;
	char		*str;
	long int	nb;

	full_size = 0;
	nb = nbr;
	if (nb <= 0)
	{
		full_size++;
		nb = -nb;
	}
	while (nb > 0)
	{
		full_size++;
		nb /= ft_strlen2(base);
	}
	str = (char *)malloc(full_size + 1);
	if (!str)
		return (NULL);
	return (str);
}

void	fill_arr(long int nb, char *base, char *str)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		str[0] = base[nb % ft_strlen2(base)];
		str[1] = '\0';
		return ;
	}
	if (nb < 0)
	{
		str[i] = '-';
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		str[i] = base[nb % ft_strlen2(base)];
		i++;
		nb /= ft_strlen2(base);
	}
	str[i] = '\0';
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int			i;
	char		*str;
	char		temp;
	long int	nb;

	nb = nbr;
	if (!check_base2(base))
		return (NULL);
	str = create_str(nbr, base);
	if (!str)
		return (NULL);
	fill_arr(nb, base, str);
	if (str[0] == '-')
		i = 0;
	else
		i = -1;
	nb = ft_strlen2(str) - 1;
	while (++i < nb)
	{
		temp = str[i];
		str[i] = str[nb];
		str[nb--] = temp;
	}
	return (str);
}
