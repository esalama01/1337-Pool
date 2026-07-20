/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:39:20 by ychaif            #+#    #+#             */
/*   Updated: 2026/07/19 18:40:12 by ychaif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_columns(int x, char a, char b, char c)
{
	int	column;

	column = 1;
	while (column <= x)
	{
		if (column == 1)
			ft_putchar(a);
		else if (column == x)
			ft_putchar(c);
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
	print_columns(x, 'A', 'B', 'A');
	ft_putchar('\n');
	row++;
	while (row < y)
	{
		print_columns(x, 'B', ' ', 'B');
		ft_putchar('\n');
		row++;
	}
	if (row == y)
	{
		print_columns(x, 'C', 'B', 'C');
		ft_putchar('\n');
	}
}
