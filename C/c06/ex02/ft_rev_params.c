/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:44:24 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/22 23:58:41 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
			i++;
		while (i > 1)
		{
			write(1, av[i - 1], ft_strlen(av[i - 1]));
			write(1, "\n", 1);
			i--;
		}
	}
	return (0);
}
