/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:44:55 by atucci            #+#    #+#             */
/*   Updated: 2023/03/08 16:56:39 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "incl/ft_printf.h"

static int placeholder(va_list *arg, char q, int count)
{
// inside this function I should do all the check for the place holder 
// %c
// %s 
// %p and so on
		
			if (q == 'c')
				count += ft_putchar(va_arg(*arg, int));
			else if (q == 's')
				count += ft_putstr(va_arg(*arg, char*));
	return (count);
}
int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args; //check the syntax
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i]) //checking the format string for placeholders
	{
		if (format[i] == '%') // once I find the placeholder
		{
		// I found the placeholder!!
			count = placeholder(&args,((char *) format) [i + 1], count); // typecasting!
			i++;
		}
		else 
		{
		// There is no placeholder so I just print what I have :(
			ft_putchar(format[i]);
			count++;
		}
	i++;
	}
	va_end(args); //check the syntax
	return (count);
}
