/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:27:25 by edbernar          #+#    #+#             */
/*   Updated: 2023/08/02 16:01:06 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void	put_x_on_tab(char **map, int best_solu[2], int par[4])
{
	int	locate[2];
	int	x;
	int	y;

	x = best_solu[0] / ft_strlen(map[0]);
	locate[0] = best_solu[0] / ft_strlen(map[0]);
	locate[1] = best_solu[0] % ft_strlen(map[0]);
	while (x < locate[0] + best_solu[1])
	{
		y = best_solu[0] % ft_strlen(map[0]);
		while (y < locate[1] + best_solu[1])
		{
			map[x][y] = par[3];
			y++;
		}
		x++;
	}
	print_map(map);
}

int	is_valid(char **map, int pos, int size, int par[4])
{
	int	locate[2];
	int	max_y;
	int	x;
	int	y;

	max_y = ft_strlen(map[0]);
	locate[0] = pos / max_y;
	locate[1] = pos % max_y;
	if (size == 1 && map[locate[0]][locate[1]] == '.')
		return (1);
	if ((size > max_y - locate[1]) || (size > par[0] - locate[0]))
		return (0);
	x = locate[0];
	while (x < par[0] && x - locate[0] < size)
	{
		y = locate[1];
		while (y < max_y && y - locate[1] < size)
		{
			if (map[x][y] == par[2])
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	main_solver(char **map, int par[4])
{
	int	best_solu[2];
	int	pos_max;
	int	pos;
	int	size;

	pos = -1;
	while (++pos < 2)
		best_solu[pos] = 0;
	pos = -1;
	pos_max = ft_strlen(map[0]) * par[0];
	while (++pos < pos_max)
	{
		size = best_solu[1] + 1;
		while (is_valid(map, pos, size, par))
		{
			if (size > best_solu[1])
			{
				best_solu[0] = pos;
				best_solu[1] = size;
			}
			size++;
		}
	}
	put_x_on_tab(map, best_solu, par);
}
