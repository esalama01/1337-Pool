/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:07:11 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/26 19:37:46 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_deplicates(int board[4][4], int row, int col, int nbr);
int	ft_check_top_visibility(int board[4][4], int col, int *clues);
int	ft_check_bottom_visibility(int board[4][4], int col, int *clues);
int	ft_check_left_visibility(int board[4][4], int row, int *clues);
int	ft_check_right_visibility(int board[4][4], int row, int *clues);

int	ft_check_visibility(int board[4][4], int row, int col, int *clues)
{
	if (col == 3 && !(ft_check_left_visibility(board, row, clues)
			&& ft_check_right_visibility(board, row, clues)))
		return (0);
	if (row == 3 && !(ft_check_top_visibility(board, col, clues)
			&& ft_check_bottom_visibility(board, col, clues)))
		return (0);
	return (1);
}

int	ft_solve_recursive(int board[4][4], int row, int col, int *clues)
{
	int	nbr;

	if (row == 4)
		return (1);
	nbr = 0;
	while (nbr <= 4)
	{
		if (ft_check_deplicates(board, row, col, nbr))
		{
			board[row][col] = nbr;
			if (ft_check_visibility(board, row, col, clues))
			{
				if (col == 3 && ft_solve_recursive(board, row + 1, 0, clues))
					return (1);
				if (col < 3 && ft_solve_recursive(board, row, col + 1, clues))
					return (1);
			}
			board[row][col] = 0;
		}
		nbr++;
	}
	return (0);
}

int	ft_solver(int board[4][4], int row, int col, int *clues)
{
	return (ft_solve_recursive(board, row, col, clues));
}
