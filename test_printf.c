#include "incl/ft_printf.h"

int	main()
{
	char *str = "stronzo";
	char C = 'c';
	ft_printf( "%c  %s",  C, str);
	write (1, "\n", 1);
	printf( "%c  %s",  C, str);
	return (0);
}
