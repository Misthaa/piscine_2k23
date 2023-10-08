/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:04:24 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/27 16:17:15 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tab = malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (-1);
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (i);
}
