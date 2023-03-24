/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:31:36 by atucci            #+#    #+#             */
/*   Updated: 2023/03/20 15:40:02 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"
#include "../libft/libft.h"

/**
 * check_sign_flags - function to check sign flags in a format string
 * @str: pointer to the format string
 * @i: index of the character in the format string
 *
 * Return: the index of the last character before the conversion specifier
 */
int check_sign_flags(const char *str, int i)
{
    int index = i + 1;
    int has_minus = 0;
    int has_space = 0;
	int has_plus = 0;

    // Check if the first character is '0'
    if (str[i] == '0')
    {
        g_bonus.is_zero = 1;
        index++;
    }

    // Loop through the string to find sign flags
    while (str[index])
    {
        // If a conversion specifier is found, exit the loop
        if (ft_strchr("cspdiuxX%", str[index]))
            break;

        // Check for the + or - flag
        if (str[index] == '+')
            has_plus = 1;
        else if (str[index] == '-')
            has_minus = 1;

        // Check for the space flag
        if (str[index] == ' ' && !has_minus)
            has_space = 1;

        // Move to the next character
        index++;
    }

    // Update the struct based on the sign flags found
    if (has_space)
        g_bonus.is_minus = 2;
    else if (has_minus)
        g_bonus.is_minus = 1;
	else if (has_plus)
		g_bonus.is_plus = 1;

    // Return the index of the last character before the conversion specifier
    return (i);
}

/**
 * check_formatting_flags - function to check formatting flags in a format string
 * @str: pointer to the format string
 * @i: index of the character in the format string
 *
 * Return: the index of the last character before the conversion specifier
 */
int check_formatting_flags(const char *str, int i)
{
    int index = i + 1;
    int has_precision = 0;
    int has_width = 0;

    // Check if the first character is '0'
    if (str[i] == '0')
    {
        g_bonus.is_zero = 1;
        index++;
    }

    // Loop through the string to find formatting flags
    while (str[index])
    {
        // If a conversion specifier is found, exit the loop
        if (ft_strchr("cspdiuxX%", str[index]))
            break;

        // Check if a digit is found
        if (ft_isdigit(str[index]))
        {
            // If neither precision nor width is found yet, it's a width
            if (!has_precision && !has_width)
                has_width = 1;
            // If precision is found, reset width and set precision to 0
            if (has_precision)
                g_bonus.precision = 0;
            g_bonus.width = g_bonus.width * 10 + (str[index] - '0');
        }

        // Check for the precision flag
        if (str[index] == '.')
        {
            has_precision = 1;
            has_width = 0;
            index++;
            // If a digit follows the '.', it's a precision
            if (ft_isdigit(str[index]))
                g_bonus.precision = ft_atoi(str + index);
            else
                g_bonus.precision = 0;
            while (ft_isdigit(str[index]))
                index++;
        }

        // Move to the next character
        index++;
    }

    // Return the index of the last character before the conversion specifier
    return (index);
}



int print_sign(int n)
{
    if (g_bonus.is_minus == 2) // if space flag is set
        return(pt_putchar(' '));
    else if (g_bonus.is_plus == 1 && n >= 0) // if plus flag is set
        return(pt_putchar('+'));
	else
		return (0);
}

