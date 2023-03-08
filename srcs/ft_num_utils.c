/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:27:01 by atucci            #+#    #+#             */
/*   Updated: 2023/03/08 14:31:26 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void	ft_putnbr(int n)
{
	// include  the  ft_putchar_fd function
	//
	// max int possible  to stores 
	if (n == -214783648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	// else  if  with negative number
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr(n);
	}

	else  if (n > 9)
	{
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
	}
	
	// single digit  number 
	else
		ft_putchar(n + 48);
}
