/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:45:04 by atucci            #+#    #+#             */
/*   Updated: 2023/03/13 18:14:36 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

#include <stdio.h> // debugging
int	ft_putchar(char c)
{
	int count;
//	int pad;

	count = 0;
/*	pad = g_bonus.width - 1;
	while (pad > 0)
	{
		count += white_spaces();
		pad--;
	}*/
	count += (write(1, &c, 1));
	return (count);
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
//	int len; //bonus
//	int padding;

//	len = ft_strlen(str);
//	padding = g_bonus.width - len;
	count = 0;
	if	(str == NULL)
	return(ft_putstr("(null)"));
	
/*	while (padding > 0)
	{
		count += white_spaces();
		padding--;
	}*/
	while (str[count])
	{
		ft_putchar(str[count]);
		count++;
	}
	return (count);
}

int width_flag(const char *format, int i, flags *g_bonus)
{
        // Calculate the width 
        int width = 0;
        while (format[i] >= '0' && format[i] <= '9')
        {
			width = width * 10 + (format[i] - '0');
            i++;
        }
		g_bonus->width = width; // accessing the  structr
		// printf("this is the  new width:%d\n", g_bonus->width);

        // Return the updated index 
        //printf ("this is the index I'm returning: %d\n", i);
		return (i);


}


