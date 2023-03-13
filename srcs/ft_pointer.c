/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:28:24 by atucci            #+#    #+#             */
/*   Updated: 2023/03/13 18:07:39 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

// Returns the number of digits in a given unsigned long integer
int	ft_len_u(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16; // Divide by 16 to get the next hexadecimal digit
		len++; // Increment the length counter
	}
	return (len);
}

// Prints the hexadecimal representation of an unsigned long integer
int	ft_pointer(unsigned long nb)
{
	char	*str; // Pointer to the string that will hold the hexadecimal representation
	char	*hex; // String of hexadecimal digits
	int		i; // Index used for constructing the hexadecimal string
	int		count;

	count = 0;
	count += ft_putstr("0x"); // Print the '0x' prefix for pointers
	hex = "0123456789abcdef"; // Set up the string of hexadecimal digits
	str = (char *)malloc((ft_len_u(nb) + 1) * sizeof(char)); // Allocate memory for the hexadecimal string
	if (!str)
		return (0);
	i = ft_len_u(nb);
	str[i] = '\0'; // Add null terminator to end of string
	i--;
	if (nb == 0)
		str[0] = '0'; // If nb is zero, set the first character of the string to '0'
	while (nb != 0)
	{
		str[i] = hex[nb % 16]; // Add the next hexadecimal digit to the string
		nb = nb / 16; // Divide by 16 to get the next hexadecimal digit
		i--; // Decrement the index to move to the next character in the string
	}
	count += ft_putstr(str); // Print the hexadecimal string
	free(str); // Free the memory allocated for the string
	return (count);
}

int	white_spaces(void)
{
	return (write(1, "  ", 1));
}
