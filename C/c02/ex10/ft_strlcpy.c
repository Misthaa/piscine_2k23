/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:09:33 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/13 22:09:15 by madegryc         ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = -1;
	if (!size)
		return (ft_strlen(src));
	while (src[++i] && i < size)
		dest[i] = src[i];
	if (i < size)
	{
		while (i < size)
		{
			dest[i] = 0;
			i++;
		}
	}
	else if (i == size)
		dest[i - 1] = 0;
	return (ft_strlen(src));
}
