/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:34:43 by atucci            #+#    #+#             */
/*   Updated: 2023/03/08 12:37:09 by atucci           ###   ########.fr       */
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

// Function prototype for ft_putchar(), which is defined in another source file.
int ft_putchar(char c);

#endif
