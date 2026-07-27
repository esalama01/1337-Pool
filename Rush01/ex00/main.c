/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:59:50 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/26 19:41:13 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int		ft_parser(char *str, int *clues);
void	ft_fill_array(int grid[4][4]);
void	ft_print_array(int grid[4][4]);
int		ft_solver(int board[4][4], int row, int col, int *clues);

int	main(int ac, char **av)
{
	int	clues[16];
	int	board[4][4];

	if (ac != 2 || !(ft_parser(av[1], clues)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_fill_array(board);
	if (ft_solver(board, 0, 0, clues))
		ft_print_array(board);
	else
		write(1, "Error\n", 6);
	return (0);
}
