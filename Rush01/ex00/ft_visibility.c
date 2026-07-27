/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@41.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:19:32 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/26 19:38:14 by elsalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_right_visibility(int board[4][4], int row, int *clues)
{
	int	j;
	int	max;
	int	total_right_visibility;

	j = 3;
	total_right_visibility = 0;
	max = 0;
	while (j >= 0)
	{
		if (board[row][j] > max)
		{
			max = board[row][j];
			total_right_visibility += 1;
		}
		j--;
	}
	return (total_right_visibility == clues[12 + row]);
}

int	ft_check_left_visibility(int board[4][4], int row, int *clues)
{
	int	j;
	int	max;
	int	total_left_visibility;

	j = 0;
	total_left_visibility = 0;
	max = 0;
	while (j < 4)
	{
		if (board[row][j] > max)
		{
			max = board[row][j];
			total_left_visibility += 1;
		}
		j++;
	}
	return (total_left_visibility == clues[8 + row]);
}

int	ft_check_top_visibility(int board[4][4], int col, int *clues)
{
	int	j;
	int	max;
	int	total_top_visibility;

	j = 0;
	total_top_visibility = 0;
	max = 0;
	while (j < 4)
	{
		if (board[j][col] > max)
		{
			max = board[j][col];
			total_top_visibility += 1;
		}
		j++;
	}
	return (total_top_visibility == clues[0 + col]);
}

int	ft_check_bottom_visibility(int board[4][4], int col, int *clues)
{
	int	j;
	int	max;
	int	total_bottom_visibility;

	j = 3;
	total_bottom_visibility = 0;
	max = 0;
	while (j >= 0)
	{
		if (board[j][col] > max)
		{
			max = board[j][col];
			total_bottom_visibility += 1;
		}
		j--;
	}
	return (total_bottom_visibility == clues[4 + col]);
}
