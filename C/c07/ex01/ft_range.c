/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:44:33 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/26 15:56:24 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*tab;

	i = 0;
	if (min >= max)
		return (0);
	size = max - min;
	tab = malloc(sizeof(int ) * size);
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
