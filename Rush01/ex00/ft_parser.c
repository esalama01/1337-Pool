/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 18:46:00 by nsadiki           #+#    #+#             */
/*   Updated: 2026/07/26 18:46:02 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Top:    clues[0]  clues[1]  clues[2]  clues[3]
Bottom: clues[4]  clues[5]  clues[6]  clues[7]
Left:   clues[8]  clues[9]  clues[10] clues[11]
Right:  clues[12] clues[13] clues[14] clues[15]
*/

int	*fill_clues(char *str, int *clues)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			clues[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (clues);
}

int	check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i % 2 == 0) && !(str[i] >= '1' && str[i] <= '4'))
			return (0);
		if ((i % 2 != 0) && !(str[i] == ' '))
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

int	ft_parser(char *str, int *clues)
{
	if (!check_input(str))
		return (0);
	clues = fill_clues(str, clues);
	return (1);
}
