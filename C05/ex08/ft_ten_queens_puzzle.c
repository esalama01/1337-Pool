/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsalama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:21:43 by elsalama          #+#    #+#             */
/*   Updated: 2026/07/27 14:44:56 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_is_valid(char *board, int row, int column)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == column + '0'
			|| board[i] == (column + row - i) + '0'
			|| board[i] == (column - row + i) + '0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_display_board(char *board)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, &board[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_tqueens_solver(char *board, int row, int *nbr)
{
	int	column;
	int	is_valid;

	if (row == 10)
	{
		ft_display_board(board);
		(*nbr)++;
	}
	else
	{
		column = 0;
		while (column < 10)
		{
			is_valid = 1;
			if (!ft_is_valid(board, row, column))
				is_valid = 0;
			if (is_valid)
			{
				board[row] = column + '0';
				ft_tqueens_solver(board, row + 1, nbr);
			}
			column++;
		}
	}
	return (*nbr);
}

int	ft_ten_queens_puzzle(void)
{
	int		counter;
	char	board[10];

	counter = 0;
	counter = ft_tqueens_solver(board, 0, &counter);
	return (counter);
}
