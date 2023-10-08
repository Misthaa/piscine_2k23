/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:35:32 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/19 16:57:10 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size < dest_len)
		src_len += size;
	else
		src_len += dest_len;
	while (src[i] != '\0' && ((dest_len + i) < size - 1))
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (src_len);
}
