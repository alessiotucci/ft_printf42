/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:45:04 by atucci            #+#    #+#             */
/*   Updated: 2023/03/22 00:53:43 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

#include <stdio.h> // debugging
int	pt_putchar(char c)
{
	return (write(1, &c, 1));
}

int	pt_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
	count++;
	return (count);
}

int	pt_putstr(char *str)
{
	int count;
	count = 0;
	if	(str == NULL)
	return (write(1, "(null)", 6));
	
	while (str[count])
	{
		pt_putchar(str[count]);
		count++;
	}
	return (count);
}
