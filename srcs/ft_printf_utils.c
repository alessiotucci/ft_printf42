/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:45:04 by atucci            #+#    #+#             */
/*   Updated: 2023/03/11 15:41:20 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

#include <stdio.h> // debugging

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

int width_flag(const char *format, int i, t_printf *tdata)
{
        /* Calculate the width */
        int width = 0;
        while (format[i] >= '0' && format[i] <= '9')
        {
            width = width * 10 + (format[i] - '0');
            i++;
        }
        tdata->width = width;

        /* Return the updated index */
        return (i - 1);

}


