/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:27:01 by atucci            #+#    #+#             */
/*   Updated: 2023/03/22 00:44:33 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

#include "../libft/libft.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	// include  the  ft_putchar_fd function
	//
	// max int possible  to stores 
	if (n == -214783648 || n == INT_MIN)
		count += pt_putstr("-2147483648");
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


// function to convert a number to a given base
int	ft_putnumber_base(unsigned long long int nbr, char *base)
{
	unsigned long long int	n;   // variable to store the current value of the number being converted
	unsigned long long int	j;   // variable to store the length of the given base
	int	i;                       // variable to store the number of characters printed (return value)
	int	len;                     // variable to store the length of the number being converted

	j = (unsigned long long int)pt_strlen(base); // get the length of the base string
	len = 1;                                     // initialize the length of the number to 1
	i = 0;                                       // initialize the number of characters printed to 0

	if ((int)nbr < 0)          // if the input number is negative,
	{
		nbr *= -1;       // make it positive
		ft_putchar_fd('-', 1); // and print a negative sign
	}
	n = nbr;               // initialize the current value of the number to the input number

	// calculate the length of the number being converted
	while ((n / len) >= j)
		len *= j;

	// convert the number to the given base
	while (len > 0)
	{
		i += pt_putchar(base[(n / len) % j]);  // print the current digit
		len /= j;                              // move to the next digit
	}

	return (i); // return the number of characters printed
}

// function to print an unsigned integer
int ft_putuns(unsigned int nbr)
{
    int i; // variable to store the number of characters printed

    // convert the unsigned integer to base 10 and print it
    i = ft_putnumber_base((unsigned long long int) nbr, "0123456789");

    return (i); // return the number of characters printed
}

int check_sign(int num)
{
	printf("this is the num %d\n" , num);
    if (num < 0)
        return -1;
    else if (num > 0)
        return 1;
    else
        return 0;
}

