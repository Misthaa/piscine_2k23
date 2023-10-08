/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:06:31 by madegryc          #+#    #+#             */
/*   Updated: 2023/08/03 14:50:00 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);

void	ft_addition(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_substract(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_division(int a, int b)
{
	ft_putnbr(a / b);
}

void	ft_multiplication(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_modulo(int a, int b)
{
	ft_putnbr(a % b);
}
