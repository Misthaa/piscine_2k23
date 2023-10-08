/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:49:58 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/20 18:48:49 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_verif(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
	{
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (-1);
	}
	if (i < 2)
		return (-1);
	return (1);
}

void	ft_print(long int nbr, char *base)
{
	if (ft_verif(base) == -1)
		return ;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr >= ft_strlen(base))
		ft_print(nbr / ft_strlen(base), base);
	write(1, &base[nbr % ft_strlen(base)], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	ft_print((long int)nbr, base);
}
