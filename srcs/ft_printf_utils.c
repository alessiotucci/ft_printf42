/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:45:04 by atucci            #+#    #+#             */
/*   Updated: 2023/03/10 16:32:16 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
	count++;
	return (count);
}

int	ft_putstr(char *str)
{
	int count;

	count = 0;
	if	(str == NULL)
	return(ft_putstr("(null)"));
	while (str[count])
	{
		ft_putchar(str[count]);
		count++;
	}
	return (count);
}

int handle_minus_flag(const char *format, int i, t_printf *tdata)
{
    /* Check if the '-' flag is present */
    if (format[i] == '-')
    {
        /* Set the is_minus flag to true */
        tdata->is_minus = 1;

        /* Move to the next character in the format string */
        i++;

        /* Calculate the width */
        int width = tdata->width;
        if (width < 0)
        {
            tdata->is_minus = 0;
            width = -width;
        }

        /* Output the placeholder with padding */
        if (format[i] == 'c')
        {
            char c = va_arg(tdata->args, int);
            ft_putchar(c);
            while (--width > 0)
                ft_putchar(' ');
        }
        else if (format[i] == 's')
        {
            char *s = va_arg(tdata->args, char *);
            int len = ft_strlen(s);
            ft_putstr(s);
            while (len < width)
            {
                ft_putchar(' ');
                len++;
            }
        }
        // add more conversion here

        /* Return the updated index */
        return i + 1;
    }

    /* Return the original index if the '-' flag is not present */
    return i;
}

