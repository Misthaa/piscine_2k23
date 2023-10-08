/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:32:22 by bseguret          #+#    #+#             */
/*   Updated: 2023/07/23 11:30:40 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mylib.h"

int	verification(char **argv)
{
	int	i;
	int	len;
	int	nb;
	int	j;
	int	size;

	i = 0;
	j = 0;
	nb = 0;
	len = 0;
	while (argv[1][len])
		len ++;
	nb = (len / 2) + 1;
	size = nb / 4;
	if (!ft_error(argv[1], nb, len, size))
		return (-1);
	while (i != nb)
	{
		argv[1][i] = argv[1][j];
		i++;
		j += 2;
	}
	argv[1][i] = '\0';
	return (size);
}

int	ft_error(char *str, int nb, int len, int size)
{
	int	i;
	int	error;

	i = 0;
	error = 1;
	if (!str[i])
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (str[i])
	{
		if (!((str[i] >= '1' && str[i] <= size + 48)
				|| str[i] == ' ') || nb % 4 != 0)
			error = 0;
		if (str[len - 1] == ' ')
			error = 0;
		i++;
	}
	if (error == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	init_tab(t_tab *tab)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	(*tab).value = malloc((*tab).size * sizeof(char *));
	while (++i < (*tab).size)
		(*tab).value[i] = malloc((*tab).size * sizeof(char));
	x = 0;
	while (x < (*tab).size)
	{
		y = 0;
		while (y < (*tab).size)
		{
			(*tab).value[x][y] = 0;
			y++;
		}
		x++;
	}
}

int	main(int ac, char **av)
{
	t_tab	tab;

	if (ac != 2)
		write(1, "Invalid number of arguments.\n", 30);
	else
	{
		tab.size = verification(av);
		if (tab.size == -1)
			return (0);
		tab.status = 1;
		init_tab(&tab);
		backtracking(&tab, 0, av[1]);
		if (tab.status == 1)
			write(1, "Error\n", 6);
		free_tab(tab.value, tab.size);
	}
}
