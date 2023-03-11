#include "incl/ft_printf.h"

int	main()
{
	char *str = "stronzo\n";
	char C = 'c';
	char *prova = "ci riprovo";
	char y = 'h';	
	ft_printf( "%c  %s",  C, str);
	write (1, "\n", 1);
	write (1, "\n", 1);

	printf( "this is the original:\n");
	printf( "%c  %s",  C, str);
	
	// Test with '-' flag present
    ft_printf("%-15c%-10s", y, prova);
    write(1, "\n", 1);
	write(1, "\n", 1);
	printf( "this is the original:\n");
   	printf("%-15c%-10s", y, prova);
    write(1, "\n", 1);

	return (0);
}
