/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:14:08 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/22 23:59:33 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_tab
{
	char	**value;
	char	*str;
	int		size;
	int		status;
}t_tab;

void	put_nbr(char ***tab, int pos, int nbr, int size);
char	**ft_tabcpy(char **tab, int size);
int		is_really_valid(char **tab, char *str, int size);
void	free_tab(char **tab, int size);
int		is_valid(t_tab tab, int pos, int nbr);
int		*define_locate(int *locate, int pos, int size);
int		ft_verif_up(char **tab, char *str, int *locate, int size);
int		ft_verif_down(char **tab, char *str, int *locate, int size);
int		ft_verif_left(char **tab, char *str, int *locate, int size);
int		ft_verif_right(char **tab, char *str, int *locate, int size);
int		ft_error(char *str, int nb, int len, int size);
void	backtracking(t_tab *tab, int pos, char *str);

#endif