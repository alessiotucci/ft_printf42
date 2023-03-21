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
	// CHATGPT suggerisce
//	int is_left_aligned = g_bonus.is_minus;
  //  int field_width = g_bonus.width;

// inside this function I should do all the check for the place holder 
// %c
// %s 
// %p and so on
	 
	//printf("\nthis is the count B4 conversion:%d\n", count);	
   // int diff = 0;
//	int x;
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
// check the values
/*  	printf("g_bonus.width = %d\n", g_bonus.width);
    printf("g_bonus.precision = %d\n", g_bonus.precision);
    printf("g_bonus.is_zero = %d\n", g_bonus.is_zero);
    printf("g_bonus.is_minus = %d\n", g_bonus.is_minus);
    printf("g_bonus.is_dot = %d\n", g_bonus.is_dot);
*/


	va_start(args, format);
	count = 0;
//	printf("\ncount should be zero but is %d\n", count);
	i = 0;
	while (format[i]) //checking the format string for placeholders
	{
		if (format[i] == '%') // once I find the placeholder
		{
		// I found the placeholder!!
	//	printf("\nWHY count is %d", count);
		// check for the flag
		 i = check_sign_flags(format, i);	
 		 
		 // commenting this part just  for now!!
		 //i  = check_formatting_flags(format, i);


		// check if the values has been updated
/*    printf("g_bonus.width UPDATED= %d\n", g_bonus.width);
    printf("g_bonus.precision UPDATED= %d\n", g_bonus.precision);
    printf("g_bonus.is_zero UPDATED= %d\n", g_bonus.is_zero);
    printf("g_bonus.is_minus UPDATED= %d\n", g_bonus.is_minus);
    printf("g_bonus.is_dot UPDATED= %d\n", g_bonus.is_dot);*/
		//count = do_flags();	
		// converting 
		
		t = print_sign();
		count = placeholder(&args,((char *) format) [i], count); // typecasting!
		//printf("\ncount is: %d\n", count);
		//	i++;
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
