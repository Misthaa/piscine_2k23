/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:48:40 by madegryc          #+#    #+#             */
/*   Updated: 2023/08/03 17:06:53 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	crois;
	int	decrois;

	i = 0;
	crois = 0;
	decrois = 0;
	if (length == 0)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			crois++;
		else if (f(tab[i], tab[i + 1]) < 0)
			decrois++;
		else
		{
			crois++;
			decrois++;
		}
		i++;
	}
	if (crois != length - 1 && decrois != length - 1)
		return (0);
	return (1);
}
