/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:04:14 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/23 00:00:10 by madegryc         ###   ########.fr       */
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

	(void)ac;
	i = 1;
	while (av[i])
	{
		write(1, av[i], ft_strlen(av[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
