/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:59:36 by elsalama          #+#    #+#             */
/*   Updated: 2026/07/18 12:25:33 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	r;
	int	d;

	d = *a / *b;
	r = *a % *b;
	ft_swap(a, &d);
	ft_swap(b, &r);
}
