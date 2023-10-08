/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:04:38 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/11 00:34:57 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	numbers(int a, int b, int c)
{
	a = a + 48;
	write(1, &a, 1);
	b = b + 48;
	write(1, &b, 1);
	c = c + 48;
	write(1, &c, 1);
	if (a - 48 < 7)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				numbers(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
