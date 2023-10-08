/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:50:05 by madegryc          #+#    #+#             */
/*   Updated: 2023/08/02 16:00:36 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int	verif_map(char *buffer)
{
	int	size;
	int	i;
	int	nbr_line;

	i = -1;
	i = ft_strlen_sp(buffer, "\n");
	if (i < 4)
		return (-1);
	size = ft_strlen_sp(&buffer[i + 1], "\n");
	nbr_line = 0;
	while (buffer[++i])
	{
		if (buffer[i - 1] == '\n')
		{
			if (ft_strlen_sp(&buffer[i], "\n") == size)
				nbr_line++;
			else
				return (-1);
		}
	}
	if (ft_atoi(buffer) != nbr_line)
		return (-1);
	return (0);
}
