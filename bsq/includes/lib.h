/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:52:38 by edbernar          #+#    #+#             */
/*   Updated: 2023/08/02 20:30:37 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		is_valid(char **map, int pos, int size, int par[4]);
int		fill_buffer(char **buffer, int fd, int *error);
int		pull_param(char *info, int (*par)[4]);
void	main_solver(char **map, int par[4]);
int		ft_strlen_sp(char *str, char *sep);
char	*ft_realloc(char *str, int size);
char	**ft_split(char *str, char *sep);
int		open_file(char *file, int *fd, int ac);
int		verif_map(char *buffer);
void	print_map(char **map);
int		ft_tablen(char **map);
void	free_tab(char **tab);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

#endif