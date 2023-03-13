#include "incl/ft_printf.h"

int	main()
{
	char *str = "stronzo\n";
	int bro = 23456;
	char C = 'c';
//	char *prova = "prova";
//	char y = 'h';	
// test without flags

	ft_printf( "%c %s %d",  C, str, bro);
	write (1, "\n", 1);
	write (1, "\n", 1);

	printf( "this is the original:\n");
	printf( "%c %s %d\n",  C, str, bro);

	// Test with '-' flag present 
/*   ft_printf("la mia:\n %5c %1s", y, prova);
    write(1, "\n", 1);
	write(1, "\n", 1);
	printf( "this is the original:\n");
   	printf("%5c %1s", y, prova);
    write(1, "\n", 1); 
*/
	return (0);
}
