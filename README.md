# ft_printf (without bonus 😢😢😢)

**CLARIFICATION OF THE SUBJECT:**

# PRINTF BUFFERS:

In computer programming, a **buffer** is a temporary storage area used to store data that is being transmitted or processed. A buffer is typically used to hold data while it is being transferred between different parts of a program, or between a program and an external device such as a file, network socket, or printer.

In the context of the printf function, **buffer management** refers to the way that the function handles the output that it generates. When printf generates output, it is usually written to a buffer before being sent to the console or other output device. This buffer is used to accumulate output until it is ready to be sent to the output device.

Buffer management is important because it allows the printf function to generate output more efficiently. By accumulating output in a **buffer** and then writing it to the output device in large chunks, the function can reduce the number of calls to the output device and improve overall performance.

In the case of the assignment you mentioned, the requirement is that you do not need to implement buffer management. This means that your implementation of ft_printf should generate output directly to the output device, without using a buffer to accumulate output. This may result in your implementation being less efficient than the original printf function, but it simplifies the implementation and avoids **some potential issues with buffer overflow and memory allocation**.

# STATIC  LIBRARY:

**A static library** is a collection of object files (i.e., compiled code) that has been combined into a single file. This file is known as a library file, and it can be used by other programs to link against and access the functions and data contained in the library.

When a program is compiled, it can be linked against a static library by including a reference to the library in the compilation process. This allows the functions and data contained in the library to be used by the program as if they were part of the program itself.

In the case of the assignment you mentioned, you are being asked to create a static library file named libftprintf.a using the ar command. This library file should contain your implementation of the ft_printf function, as well as any other functions or data that are required by your implementation.

  ### How I structured my project
| function name | Description | youtube links |
 | ----------------------------- | ------------------------------------------------- | ------------------------------------------------------- |
   | [`ft_printf`](https://github.com/alessiotucci/ft_printf/blob/master/ft_printf.c) | description | video|
 | [`Makefile`](https://github.com/alessiotucci/ft_printf/blob/master/Makefile) | description | video|
 | [`test_printf`](https://github.com/alessiotucci/ft_printf/blob/master/test_printf.c) | description | video|
  | [`incl folder`](https://github.com/alessiotucci/ft_printf/blob/master/incl) | description | video| 
   | [`srcs folder`](https://github.com/alessiotucci/ft_printf/blob/master/srcs) | description | video| 
   | [`libft`](https://github.com/alessiotucci/libft_42) | description | video|
   
   
   
   **Day 1:**



* Set up a new C project in your development environment.
* Create a header file named ft_printf.h.
* Declare the prototype of the function ft_printf() in the header file.
* Create a source file named ft_printf.c.
* Write the function ft_printf() with no functionality yet.
* Build the project and make sure it compiles without errors.

**Day 2:**



* Learn the basics of C string handling and memory allocation.
* Implement the conversion specifier %c in the ft_printf() function.
* Test the %c conversion specifier with simple test cases.

**Day 3:**



* Learn how to use variable arguments in C.
* Implement the conversion specifier %s in the ft_printf() function.
* Test the %s conversion specifier with simple test cases.

**Day 4:**



* Learn how to work with pointers and memory addresses in C.
* Implement the conversion specifier %p in the ft_printf() function.
* Test the %p conversion specifier with simple test cases.

**Day 5:**



* Learn how to convert integers to strings in C.
* Implement the conversion specifiers %d, %i, and %u in the ft_printf() function.
* Test the %d, %i, and %u conversion specifiers with simple test cases.

**Day 6:**



* Learn how to work with hexadecimal numbers in C.
* Implement the conversion specifiers %x and %X in the ft_printf() function.
* Test the %x and %X conversion specifiers with simple test cases.

**Day 7:**



* Implement the conversion specifier %% in the ft_printf() function.
* Learn how to handle format flags and width in C.
* Implement the format flags and width support for the conversion specifiers.
* Test the combined functionality of the format flags and conversion specifiers.
* Refactor the code and improve the design.
* Write the documentation and makefile.
* Build and test the project thoroughly.

 # **DAY 1 PROGRESS**

Compile test_printf.c and link it with lift printf.a using the following command:


```C
gcc -Wall -Wextra -Werror -o test_printf test_printf.c -L. -lftprintf```

  
