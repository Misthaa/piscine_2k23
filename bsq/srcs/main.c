/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:46:50 by edbernar          #+#    #+#             */
/*   Updated: 2023/08/02 20:30:54 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = 0;
		i++;
	}
	free(tab);
	tab = 0;
}

char	*ft_realloc(char *str, int size)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc((size + 1) * sizeof(char));
	if (new_str == NULL)
		return (0);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	free(str);
	str = 0;
	return (new_str);
}

void	free_buffer(char *buffer)
{
	int	i;

	i = -1;
	while (buffer[++i])
		buffer[i] = 0;
	free(buffer);
}

int	ft_create_map(char ***map, int fd)
{
	char	*buffer;
	int		error;

	buffer = malloc(1);
	if (buffer == NULL)
		return (-1);
	buffer[0] = 0;
	error = 0;
	if (fill_buffer(&buffer, fd, &error) || verif_map(buffer) == -1)
	{
		write(2, "map error\n", 10);
		free_buffer(buffer);
		return (-1);
	}
	*map = ft_split(buffer, "\n");
	if (ft_tablen(*map) < 2 || error || *map == NULL)
	{
		write(2, "map error\n", 10);
		free_buffer(buffer);
		free_tab(*map);
		return (-1);
	}
	free_buffer(buffer);
	return (0);
}

int	main(int ac, char **av)
{
	char	**map;
	int		par[4];
	int		fd;
	int		i;

	i = 0;
	fd = 1;
	if (ac == 1)
		fd = 0;
	while (ac++ == 1 || av[++i])
	{
		if (fd != 0 && open_file(av[i], &fd, ac) == -1)
			continue ;
		if (ft_create_map(&map, fd) != -1)
		{
			if (pull_param(map[0], &par) != -1)
				main_solver(&map[1], par);
			else
				write(2, "map error\n", 10);
			free_tab(map);
		}
		if (ac > 3)
			write(1, "\n", 1);
		close(fd);
	}
}
