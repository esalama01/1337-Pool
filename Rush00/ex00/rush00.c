/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:54:15 by ychaif            #+#    #+#             */
/*   Updated: 2026/07/19 18:23:09 by ychaif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_columns(int x, char a, char b)
{
	int	column;

	column = 1;
	while (column <= x)
	{
		if (column == 1 || column == x)
			ft_putchar(a);
		else
			ft_putchar(b);
		column++;
	}
}

void	rush(int x, int y)
{
	int	row;

	if (x <= 0 || y <= 0)
		return ;
	row = 1;
	print_columns(x, 'o', '-');
	ft_putchar('\n');
	row++;
	while (row < y)
	{
		print_columns(x, '|', ' ');
		ft_putchar('\n');
		row++;
	}
	if (row == y)
	{
		print_columns(x, 'o', '-');
		ft_putchar('\n');
	}
}
