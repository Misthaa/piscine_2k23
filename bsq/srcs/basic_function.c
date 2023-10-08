/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:04:11 by edbernar          #+#    #+#             */
/*   Updated: 2023/08/02 20:31:14 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_tablen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	print_map(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		write(1, map[x], ft_strlen(map[x]));
		write(1, "\n", 1);
		x++;
	}
}

int	fill_buffer(char **buffer, int fd, int *error)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1))
	{
		if (i % 1000 == 0)
			*buffer = ft_realloc(*buffer, (1000 * (1 + i / 1000)));
		if (buffer == NULL)
			return (-1);
		(*buffer)[i] = c;
		(*buffer)[i + 1] = 0;
		if (i > 1 && (*buffer)[i - 1] == '\n' && c == '\n')
			*error += 1;
		i++;
	}
	return (0);
}

int	open_file(char *file, int *fd, int ac)
{
	*fd = open(file, O_RDWR);
	if (*fd == -1)
	{
		write(2, "map error\n", 10);
		if (ac > 3)
			write(1, "\n", 1);
		return (-1);
	}
	return (0);
}
