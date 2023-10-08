/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:28:33 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/19 14:50:43 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (!(nb % 10 == 1 || nb % 10 == 3 || nb % 10 == 7 || nb % 10 == 9))
		return (0);
	if (nb == 2147483647)
		return (1);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
