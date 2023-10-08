/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:53:26 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/26 23:18:53 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char ) * (ft_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	i = 0;
	tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (tab == NULL)
		return (NULL);
	if (ac > 0)
	{
		while (i < ac)
		{
			tab[i].size = ft_strlen(av[i]);
			tab[i].str = av[i];
			tab[i].copy = ft_strdup(tab[i].str);
			i++;
		}
	}
	tab[i].str = 0;
	return (tab);
}
