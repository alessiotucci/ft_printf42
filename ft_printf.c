/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:44:55 by atucci            #+#    #+#             */
/*   Updated: 2023/03/10 17:28:49 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "incl/ft_printf.h"

// global variable (?)
t_printf g_printf;

void init_tdata(t_printf *tdata)
{
	tdata->ret = 0;
	tdata->width = 0;
	tdata->precision = -1;
	//The precision field is initialized to -1 because it's used to indicate that no precision was specified
	tdata->is_zero = 0;
	tdata->is_minus = 0;
	tdata->is_dot = 0;
}

static int placeholder(va_list *arg, char q, int count)
{
// inside this function I should do all the check for the place holder 
// %c
// %s 
// %p and so on
 
	t_printf tdata; // Create an instance of the t_printf struct
    init_tdata(&tdata); // Pass a pointer to the instance to the init_tdata function



/* Check if the 'minus' flag is present */
    if (tdata.is_minus)
    {
        /* Left-align the output by adding spaces to the right */
        while (count < tdata.width)
        {
            ft_putchar(' ');
            count++;
        }
    }

    /* Perform the appropriate conversion */	
			if (q == 'c')
				count += ft_putchar(va_arg(*arg, int));
			else if (q == 's')
				count += ft_putstr(va_arg(*arg, char*));
			// add more conversion here
	// call handle_minus_flag if is minus is set in t_printf struct
	if (g_printf.is_minus)
	{
		const char *format = va_arg(*arg, const char *);
		count = handle_minus_flag(format, count, &g_printf);
	}
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
