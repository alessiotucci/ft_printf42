/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:44:55 by atucci            #+#    #+#             */
/*   Updated: 2023/03/22 00:51:40 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "incl/ft_printf.h"

// global variable (?)
flags g_bonus;



void init_tdata(flags *data)
{
	data->width = 0;
	data->precision = -1;
	//The precision field is initialized to -1 because it's used to indicate that no precision was specified
	data->is_zero = 0;
	data->is_minus = 0;
	data->is_plus = 0;
	data->is_dot = 0;
}
static int placeholder(va_list *arg, char q, int count)
{
	//Perform the appropriate conversion 	
			if (q == 'c')
				count += pt_putchar(va_arg(*arg, int));
			else if (q == 's')
				count += pt_putstr(va_arg(*arg, char*));
			else if (q == 'd' || q == 'i')
				count += ft_putnbr(va_arg(*arg, int));
			else if (q == 'p')
				count += ft_pointer(va_arg(*arg, unsigned long));
			else if (q == '%')
				count += pt_putchar('%');
			// add more conversion here
			else if (q == 'u')
				count+= ft_putuns(va_arg(*arg, unsigned int));
			else if (q == 'x')
				count += ft_putnumber_base(va_arg(*arg, unsigned int), "0123456789abcdef");
			else if (q == 'X')
				count += ft_putnumber_base(va_arg(*arg, unsigned int), "0123456789ABCDEF");
			// CHEATER  COPIED FROM GITHUB 		
		
		return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args; //check the syntax
	int t;
    
	init_tdata(&g_bonus);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i]) //checking the format string for placeholders
	{
		if (format[i] == '%') // once I find the placeholder
		{
		// check for the flag
		 i = check_sign_flags(format, i);	
		 i  = check_formatting_flags(format, i);
			// CHAT GPT
			int n = 1;
			if (g_bonus.is_plus)
			{
			    va_list arg_copy;
			    va_copy(arg_copy, args);
			    n = check_sign(va_arg(arg_copy, int));
			va_end(arg_copy);
			} 
			// TRY HARD 
		t = print_sign(n);
		count = placeholder(&args,((char *) format) [i], count); // typecasting!
		}
		else 
		{
		// There is no placeholder so I just print what I have :(
		count += pt_putchar(format[i]);
		}
	i++;
	}
	va_end(args); //check the syntax
	return (count + t);
}
