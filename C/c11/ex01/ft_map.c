/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:06:23 by madegryc          #+#    #+#             */
/*   Updated: 2023/08/03 15:44:41 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	i = 0;
	result = malloc(sizeof(int) * length);
	if (result == NULL)
		return (0);
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
