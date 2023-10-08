/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:01:46 by madegryc          #+#    #+#             */
/*   Updated: 2023/07/31 13:31:33 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	words_len(char *str, char *sep)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && is_charset(sep, str[i]))
			i++;
		if (str[i])
			word++;
		while (str[i] && !is_charset(sep, str[i]))
			i++;
	}
	return (word);
}

int	ft_strlen_sp(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(sep, str[i]))
		i++;
	return (i);
}

char	**ft_split(char *str, char *sep)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	strs = malloc(sizeof(char *) * (words_len(str, sep) + 1));
	if (strs == NULL)
		return (0);
	i = 0;
	k = 0;
	while (i < words_len(str, sep))
	{
		j = 0;
		while (str[k] && is_charset(sep, str[k]))
			k++;
		strs[i] = malloc((ft_strlen_sp(&str[k], sep) + 1) * sizeof(char));
		if (strs[i] == NULL)
			return (0);
		while (str[k] && !is_charset(sep, str[k]))
			strs[i][j++] = str[k++];
		strs[i][j] = 0;
		i++;
	}
	strs[i] = 0;
	return (strs);
}
