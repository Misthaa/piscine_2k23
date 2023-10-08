/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:52:25 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/22 23:15:57 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mylib.h"

int	*define_locate(int *locate, int pos, int size)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (i == pos)
			{
				locate[0] = x;
				locate[1] = y;
				return (locate);
			}
			y++;
			i++;
		}
		x++;
	}
	return (0);
}

int	ft_verif_up(char **tab, char *str, int *locate, int size)
{
	int	verif_view;
	int	last_view;
	int	count;
	int	x;

	verif_view = str[locate[1]] - 48;
	last_view = 0;
	x = 0;
	count = 0;
	while (x < size)
	{
		if (tab[x][locate[1]] > last_view)
		{
			last_view = tab[x][locate[1]];
			count++;
		}
		x++;
	}
	if (count == verif_view)
		return (0);
	return (1);
}

int	ft_verif_down(char **tab, char *str, int *locate, int size)
{
	int	verif_view;
	int	last_view;
	int	count;
	int	x;

	verif_view = str[size + locate[1]] - 48;
	last_view = 0;
	x = size - 1;
	count = 0;
	while (x > -1)
	{
		if (tab[x][locate[1]] > last_view)
		{
			last_view = tab[x][locate[1]];
			count++;
		}
		x--;
	}
	if (count == verif_view)
		return (0);
	return (1);
}

int	ft_verif_left(char **tab, char *str, int *locate, int size)
{
	int	verif_view;
	int	last_view;
	int	count;
	int	y;

	verif_view = str[size * 2 + locate[0]] - 48;
	last_view = 0;
	y = 0;
	count = 0;
	while (y < size)
	{
		if (tab[locate[0]][y] > last_view)
		{
			last_view = tab[locate[0]][y];
			count++;
		}
		y++;
	}
	if (count == verif_view)
		return (0);
	return (1);
}

int	ft_verif_right(char **tab, char *str, int *locate, int size)
{
	int	verif_view;
	int	last_view;
	int	count;
	int	y;

	verif_view = str[size * 3 + locate[0]] - 48;
	last_view = 0;
	y = size - 1;
	count = 0;
	while (y > -1)
	{
		if (tab[locate[0]][y] > last_view)
		{
			last_view = tab[locate[0]][y];
			count++;
		}
		y--;
	}
	if (count == verif_view)
		return (0);
	return (1);
}
