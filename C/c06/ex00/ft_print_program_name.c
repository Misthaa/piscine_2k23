/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:46:16 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/23 00:00:50 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	char	*out;

	(void)ac;
	out = av[0];
	while (*out)
	{
		write(1, out, 1);
		out++;
	}
	write(1, "\n", 1);
	return (0);
}
