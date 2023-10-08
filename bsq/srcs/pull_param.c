/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:17:22 by madegryc          #+#    #+#             */
/*   Updated: 2023/08/02 14:38:44 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] >= 48 && str[i] <= '9' && (str[i + 3] && str[i + 3] != '\n'))
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (str[i + 3] && str[i + 3] != '\n')
		return (-1);
	return (nb);
}

int	pull_param(char *info, int (*par)[4])
{
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
	(*par)[0] = ft_atoi(info);
	if (!(*par)[0])
		return (-1);
	return (0);
}
