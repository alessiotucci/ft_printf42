#include "incl/ft_printf.h"


int	main()
{
    char *str = "hey";
    int num = 1234;
    char c = 'a';
	int a;
	int b;
    int e;
	int f;
	// Test with no flags
    printf("Test with no flags\n\n");
	a = printf("org %d %s %c\n", num, str, c);
    b = ft_printf("mio %d %s %c\n", num, str, c);
   	printf("original RETURNS: %d\n" , a);
	printf("aModoMio RETURNS: %d\n", b);
	
	
	write(1, "\n", 1);

	//  test  moulinette
	printf("TEST moulinnetta\n\n");
	int x = printf("%s", "");
	printf("\nla mia  torna\n");
	int y = ft_printf("%s", "");
   	printf("\noriginal RETURNS: %d\n" , x);
	printf("aModoMio RETURNS: %d\n", y);


    // Test with '-' flag for left justification
	printf("Test with '-' flag for left justification\n\n");
   	printf("original: %9s %3d\n", str, num);
    ft_printf("fatto in casa: %9s %3d\n", str, num);
    write(1, "\n", 1);

    
	//Test with '+' flag for signed numbers
    printf("Test with '+' flag for signed numbers\n\n");
	printf("original: %+d %+d\n", num, -num);
    ft_printf("HomeMade: %+d %+d\n", num, -num);
    write(1, "\n", 1);
    
   	//Test with '0' flag for zero padding
    printf("Test with '0' flag for zero paddinig\n\n");
	printf("original: %07d\n", num);
    printf("original RETURNS: %d\n" , e);
	printf("aModoMio RETURNS: %d\n", f);
	ft_printf("fatto in casa: %07d\n", num);
    write(1, "\n", 1);


	// Test with ' ' flag for space before positive number
	printf("Test with ' ' flag for space before positive number\n\n");
	e = printf("original: % d % d\n", num, -num);
	f = ft_printf("homeMade: % d % d\n", num, -num);
    printf("original RETURNS: %d\n" , e);
	printf("aModoMio RETURNS: %d\n", f);
   	write(1, "\n", 1);
    //Test with '.' flag for precision
    printf("Test with '.' flag for precision\n\n");
	printf("original: %.2s\n", str);
    ft_printf("fatto in casa: %.2s\n", str);
    write(1, "\n", 1);
    return (0);
}

