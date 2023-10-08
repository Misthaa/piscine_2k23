/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:17:22 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/31 23:07:41 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pull_param(char *info, int (*par)[4])
{
	int	len;
	int	i;
	int	size;

	i = 3;
	size = ft_strlen(info);
	if (size < 4)
		return (-1);
	size--;
	while (i > 0)
	{
		(*par)[i] = info[size];
		i--;
		size--;
	}
	if ((*par)[1] == (*par)[2])
		return (-1);
	if ((*par)[2] == (*par)[3])
		return (-1);
	if ((*par)[1] == (*par)[3])
		return (-1);
	return (max_size(par));
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i + 3] != 0)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	else
		return (-1);
	if (str[i + 3])
		return (-1); 
	return (nb);
}

int	ft_strlen_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	max_size(int (*par)[4])
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen_line(map);
	if (par[0] == size)
		return (0);
	return (-1);
}
