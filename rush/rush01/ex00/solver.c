/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:13:48 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/22 23:56:50 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mylib.h"

void	print_tab(char **tab, int size)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			c = tab[x][y] + 48;
			write(1, &c, 1);
			write(1, " ", 1);
			y++;
		}
		x++;
		write(1, "\n", 1);
	}
}

void	put_nbr(char ***tab, int pos, int nbr, int size)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			if (nbr == -1 && i == pos)
			{
				(*tab)[x][y] = 0;
				return ;
			}
			if (i == pos)
			{
				(*tab)[x][y] = nbr;
				return ;
			}
			i++;
		}
	}
}

char	**ft_tabcpy(char **tab, int size)
{
	char	**new_tab;
	int		x;
	int		y;

	new_tab = malloc(size * sizeof(char *));
	if (new_tab == NULL)
		return (0);
	x = 0;
	while (x < size)
	{
		new_tab[x] = malloc(size * sizeof(char));
		if (new_tab[x] == NULL)
			return (0);
		y = 0;
		while (y < size)
		{
			new_tab[x][y] = tab[x][y];
			y++;
		}
		x++;
	}
	return (new_tab);
}

void	free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	backtracking(t_tab *tab, int pos, char *str)
{
	int	i;

	i = 1;
	if (pos == (*tab).size * (*tab).size)
	{
		if (is_really_valid((*tab).value, str, (*tab).size) == 1)
		{
			print_tab((*tab).value, (*tab).size);
			(*tab).status = 0;
		}
		return ;
	}
	while (i <= (*tab).size && (*tab).status)
	{
		if (is_valid((*tab), pos, i))
		{
			put_nbr(&(*tab).value, pos, i, (*tab).size);
			backtracking(tab, pos + 1, str);
			put_nbr(&(*tab).value, pos, -1, (*tab).size);
		}
		i++;
	}
	return ;
}
