/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:37:01 by elsalama          #+#    #+#             */
/*   Updated: 2026/07/23 13:08:35 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l1;
	unsigned int	l2;

	i = 0;
	l1 = ft_strlen(src);
	l2 = ft_strlen(dest);
	if (size <= l2)
		return (l1 + size);
	while (src[i] != '\0' && i < size - l2 - 1)
	{
		dest[l2 + i] = src[i];
		i++;
	}
	dest[l2 + i] = '\0';
	return (l1 + l2);
}
