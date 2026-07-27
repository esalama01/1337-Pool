/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_deplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:55:32 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/26 19:40:31 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_row(int board[4][4], int row, int nbr)
{
	int	col;

	col = 0;
	while (board[row][col])
	{
		if (board[row][col] == nbr)
		{
			return (0);
		}
		col++;
	}
	return (1);
}

int	ft_check_col(int board[4][4], int col, int nbr)
{
	int	row;

	row = 0;
	while (board[row][col])
	{
		if (board[row][col] == nbr)
		{
			return (0);
		}
		row++;
	}
	return (1);
}

int	ft_check_deplicates(int board[4][4], int row, int col, int nbr)
{
	if (!(ft_check_col(board, col, nbr) && ft_check_row(board, row, nbr)))
	{
		return (0);
	}
	return (1);
}
