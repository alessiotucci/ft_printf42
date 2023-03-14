#include "incl/ft_printf.h"


int	main()
{
    char *str = "test string";
    int num = 12345;
    char c = 'a';
    
    // Test with no flags
    printf("Test with no flags\n\n");
	printf("original: %d %s %c\n", num, str, c);
    ft_printf("fatto in casa: %d %s %c\n", num, str, c);
   	write(1, "\n", 1);

    // Test with '-' flag for left justification
	printf("Test with '-' flag for left justification\n\n");
   	printf("original: %-10s %d\n", str, num);
    ft_printf("fatto in casa: %-10s %d\n", str, num);
    write(1, "\n", 1);

    // Test with '+' flag for signed numbers
    printf("Test with '+' flag for signed numbers\n\n");
	printf("original: %+d %+d\n", num, -num);
    ft_printf("fatto in casa: %+d %+d\n", num, -num);
    write(1, "\n", 1);
    // Test with '0' flag for zero padding
    printf("Test with '0' flag for zero paddinig\n\n");
	printf("original: %05d\n", num);
    ft_printf("fatto in casa: %05d\n", num);
    write(1, "\n", 1);
    // Test with ' ' flag for space before positive number
	printf("Test with ' ' flag for space before positive number\n\n");
	printf("original: % d % d\n", num, -num);
    ft_printf("fatto in casa: % d % d\n", num, -num);
    write(1, "\n", 1);
    // Test with '.' flag for precision
    printf("Test with '.' flag for precision\n\n");
	printf("original: %.2s\n", str);
    ft_printf("fatto in casa: %.2s\n", str);
    write(1, "\n", 1);
    return (0);
}

