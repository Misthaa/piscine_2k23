/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:38:20 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/20 18:48:57 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	pos_str(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (i);
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 0;
	nb = 0;
	if (ft_verif(base) == -1)
		return (0);
	while (str[i] == ' ' && str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (pos_str(str[i], base) > -1 && str[i])
	{
		nb = nb * ft_strlen(base) + pos_str(str[i], base);
		i++;
	}
	if (sign % 2)
		return (-nb);
	return (nb);
}
