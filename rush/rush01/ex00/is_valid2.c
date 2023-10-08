/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:51:43 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/22 23:59:51 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mylib.h"

int	ft_verif_around(char **tab, int *locate, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		if (tab[x][locate[1]] == tab[locate[0]][locate[1]] && x != locate[0])
			return (1);
		x++;
	}
	y = 0;
	while (y < size)
	{
		if (tab[locate[0]][y] == tab[locate[0]][locate[1]] && y != locate[1])
			return (1);
		y++;
	}
	return (0);
}

int	is_really_valid(char **tab, char *str, int size)
{	
	int	i;
	int	*locate;

	i = 0;
	locate = malloc(2 * sizeof(int));
	while (i < size * size)
	{
		locate = define_locate(locate, i, size);
		if (ft_verif_up(tab, str, locate, size)
			|| ft_verif_down(tab, str, locate, size))
		{
			free(locate);
			return (0);
		}
		if (ft_verif_left(tab, str, locate, size)
			|| ft_verif_right(tab, str, locate, size))
		{
			free(locate);
			return (0);
		}
		i++;
	}
	free(locate);
	return (1);
}

int	is_valid(t_tab tab, int pos, int nbr)
{
	int		*locate;
	char	**test_tab;

	test_tab = ft_tabcpy(tab.value, tab.size);
	put_nbr(&test_tab, pos, nbr, tab.size);
	locate = malloc(2 * sizeof(int));
	if (locate == NULL)
		return (0);
	locate = define_locate(locate, pos, tab.size);
	if (ft_verif_around(test_tab, locate, tab.size))
	{
		free(locate);
		free_tab(test_tab, tab.size);
		return (0);
	}
	free(locate);
	free_tab(test_tab, tab.size);
	return (1);
}
