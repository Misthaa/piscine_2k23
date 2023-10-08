/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:42:20 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/27 16:26:37 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_part2(int size, char **strs, char *sep, int len2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	str = malloc(sizeof(char) * (len2 + 1));
	if (str == NULL)
		return (0);
	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[len++] = strs[i][j++];
		i++;
		if (i < size)
		{
			j = 0;
			while (sep[j])
				str[len++] = sep[j++];
		}
	}
	str[len] = 0;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	if (strs == NULL || size == 0 || sep == NULL)
	{
		str = malloc(1);
		str[i] = 0;
		return (str);
	}
	while (i < size)
	{
		len = len + ft_strlen(strs[i++]);
		if (i < size)
			len = len + ft_strlen(sep);
	}
	return (ft_strjoin_part2(size, strs, sep, len));
}
