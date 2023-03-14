/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:27:01 by atucci            #+#    #+#             */
/*   Updated: 2023/03/14 12:47:10 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	// include  the  ft_putchar_fd function
	//
	// max int possible  to stores 
	if (n == -214783648)
	{
		count += pt_putchar('-');
		count += pt_putchar('2');
		count += ft_putnbr(147483648);
	}
	// else  if  with negative number
	else if (n < 0)
	{
		count += pt_putchar('-');
		n = -n;
		count += ft_putnbr(n);
	}

	else  if (n > 9)
	{
	count += ft_putnbr(n / 10);
	count += ft_putnbr(n % 10);
	}
	
	// single digit  number 
	else
	{
		count += pt_putchar(n + 48);
	}
	return (count);
}
