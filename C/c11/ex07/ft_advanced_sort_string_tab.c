/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:09:56 by madegryc          #+#    #+#             */
/*   Updated: 2023/08/03 19:29:31 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = i;
		while (j > 0 && cmp(tab[j - 1], tab[j]) > 0)
		{
			ft_swap(tab + j, tab + j - 1);
			j--;
		}
		i++;
	}
}
