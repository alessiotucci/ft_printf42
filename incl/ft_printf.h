/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:34:43 by atucci            #+#    #+#             */
/*   Updated: 2023/03/22 00:42:34 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This header file is used to declare the functions and libraries required for the printf project.
// It provides a function prototype for ft_putchar() function, which is defined in another source file.

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
// The <stdarg.h> header file provides a way to pass a variable number of arguments to a function.
#include <stdarg.h>

// The <stdio.h> header file provides a set of functions that allow you to perform input and output operations in C.
#include <stdio.h>

// The <unistd.h> header file provides access to the POSIX operating system API.
#include <unistd.h>

// The <stdlib.h> header file provides general-purpose functions for dynamic memory allocation, random number generation, communication with the environment, integer arithmetics, searching, sorting, and converting.
#include <stdlib.h>

// The <limits.h> header file provides the limits for MIN_INT
#include <limits.h> 
//The struct t_printf is used to store relevant information about the format string and the corresponding arguments. Here's a brief explanation of each field

/* args: This is a va_list object that allows us to access each argument passed to ft_printf. We need this to be able to handle variable argument lists.

ret: This is an integer that keeps track of the number of characters printed so far. We'll update this every time we print something.

width: This integer represents the field width specified in the format string. If no width is specified, it defaults to zero.

precision: This integer represents the precision specified in the format string. If no precision is specified, it defaults to -1.

is_zero: This integer is a flag that is set to 1 if the '0' flag is specified in the format string. This flag is used to determine whether to pad with zeroes or spaces.

is_minus: This integer is a flag that is set to 1 if the '-' flag is specified in the format string. This flag is used to determine whether to left-align the output.

is_dot: This integer is a flag that is set to 1 if the '.' flag is specified in the format string. This flag is used to determine whether a precision was specified in the format string.*/ 

typedef struct
{
    int width;
    int precision;
    int is_zero;
    int is_minus;
    int is_plus;
	int is_dot;
}				flags;

//global variable GPT
extern	flags g_bonus;

// Function prototype for ft_putchar(), which is defined in another source file.
int		pt_putchar(char c);

int		pt_strlen(const char *str);


int		ft_putnbr(int n);

int		pt_putstr(char *str);

int		ft_printf(const char *format, ...);

int		ft_len_u(unsigned long n);

int		ft_pointer(unsigned long nb);

int	ft_putnumber_base(unsigned long long int nbr, char *base);

int  check_sign(int num);

int ft_putuns(unsigned int nbr);
// bonus function (?)
int check_sign_flags(const char *str, int i);

int pt_print_padding(char c, int width);

int check_formatting_flags(const char *str, int i);

int print_sign(int n);

#endif
