/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:18:42 by madegryc          #+#    #+#             */
/*   Updated: 2023/08/03 14:57:29 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_addition(int a, int b);
void	ft_substract(int a, int b);
void	ft_division(int a, int b);
void	ft_multiplication(int a, int b);
void	ft_modulo(int a, int b);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 0;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (sign % 2)
		return (-nb);
	return (nb);
}

void	ft_calc(char **av, void (**f)(int, int))
{
	if (!ft_strcmp(av[2], "+"))
		f[0](ft_atoi(av[1]), ft_atoi(av[3]));
	else if (!ft_strcmp(av[2], "-"))
		f[1](ft_atoi(av[1]), ft_atoi(av[3]));
	else if (!ft_strcmp(av[2], "*"))
		f[2](ft_atoi(av[1]), ft_atoi(av[3]));
	else if (!ft_strcmp(av[2], "/"))
	{
		if (!ft_atoi(av[3]))
			write(1, "Stop : division by zero", 23);
		else
			f[3](ft_atoi(av[1]), ft_atoi(av[3]));
	}
	else if (!ft_strcmp(av[2], "%"))
	{
		if (!ft_atoi(av[3]))
			write(1, "Stop : modulo by zero", 21);
		else
			f[4](ft_atoi(av[1]), ft_atoi(av[3]));
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	void	(*f[5])(int, int);

	f[0] = ft_addition;
	f[1] = ft_substract;
	f[2] = ft_multiplication;
	f[3] = ft_division;
	f[4] = ft_modulo;
	if (ac != 4)
		return (0);
	ft_calc(av, f);
}
