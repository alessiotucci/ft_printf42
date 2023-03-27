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

gcc -Wall -Wextra -Werror -o test_printf test_printf.c -L. -lftprintf

```

**DAY 1: BONUS IMPLEMENTATION**

If you plan to complete the bonus part, think about the implementation of your extra features from the start. This way, you will avoid the pitfalls of a naive approach.


   # left-justify
   the argument within the given field width.**
For the - flag, you would need to check if it is present in the format string and adjust the padding of the output accordingly. You could also use the * specifier to read the field width from the argument list.
```C
        printf("|%10s|\n", "Hello");
        // Output: |     Hello|
        printf("|%-10s|\n", "Hello");
        // Output: |Hello     |
```
# 0: 
if the width of the field is specified, left-pads the number with zeros instead of spaces.** 
For the 0 flag,
you would need to check if it is present in the format string and, if so, use 0 instead of for the padding. Again, you could use the * specifier to read the field width from the argument list.


```C
        printf("|%05d|\n", 42); // Output: |00042|
```
# specifies the precision of a floating-point number. 
For integers, this flag has no effect.**
  For the `.` flag,
 you would need to read the precision specifier from the format string and use it to format floating-point numbers. For integers, you could simply ignore it.
```C
        printf("|%.2f|\n", 3.141592); // Output: |3.14|
```
#  #:
 **used with the o, x, or X conversion characters to prefix the output value with 0, 0x, or 0X, respectively.**
For the `#` flag,
you would need to check if it is present and, if so, prefix the output value with the appropriate string (0, 0x, or 0X).
```C
        printf("|%#x|\n", 42);       // Output: |0x2a|
        printf("|%#o|\n", 42);       // Output: |052|
        printf("|%#.2f|\n", 3.141592); // Output: |3.14|
```
# prints the sign (+ or -) of a signed number. 
If the number is positive, a plus sign is printed.**
For the `+` flag,
you would need to check if the number is positive and, if so, print a plus sign. If it is negative, you would need to print a minus sign instead.
```C
        printf("|%+d|\n", 42); // Output: |+42|
```
# **` `  (space) flag:**
** This flag is used to print a space before a positive number, if no sign is displayed.**
```C
        printf("|% d|\n", 42); // Output: | 42|
        printf("|% d|\n", -42); // Output: |-42|
``` 



<!-----

You have some errors, warnings, or alerts. If you are using reckless mode, turn it off to see inline alerts.
* ERRORs: 0
* WARNINGs: 0
* ALERTS: 3

Conversion time: 1.339 seconds.


Using this Markdown file:

1. Paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β34
* Mon Mar 27 2023 03:53:24 GMT-0700 (PDT)
* Source doc: FT_printf plan
* This is a partial selection. Check to make sure intra-doc links work.
* This document has images: check for >>>>>  gd2md-html alert:  inline image link in generated source and store images to your server. NOTE: Images in exported zip file from Google Docs may not appear in  the same order as they do in your doc. Please check the images!

----->


<p style="color: red; font-weight: bold">>>>>>  gd2md-html alert:  ERRORs: 0; WARNINGs: 0; ALERTS: 3.</p>
<ul style="color: red; font-weight: bold"><li>See top comment block for details on ERRORs and WARNINGs. <li>In the converted Markdown or HTML, search for inline alerts that start with >>>>>  gd2md-html alert:  for specific instances that need correction.</ul>

<p style="color: red; font-weight: bold">Links to alert messages:</p><a href="#gdcalert1">alert1</a>
<a href="#gdcalert2">alert2</a>
<a href="#gdcalert3">alert3</a>

<p style="color: red; font-weight: bold">>>>>> PLEASE check and correct alert issues and delete this message and the inline alerts.<hr></p>


**DAY 2 PROGRESS  **



<p id="gdcalert1" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image1.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert2">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image1.png "image_tooltip")


**The struct **t_printf is used to store relevant information about the format string and the corresponding arguments. Here's a brief explanation of each field:



* **ret:** This is an integer that keeps track of the number of characters printed so far. We'll update this every time we print something.
* **width:** This integer represents the field width specified in the format string. If no width is specified, it defaults to zero.
* **precision:** This integer represents the precision specified in the format string. If no precision is specified, it defaults to -1.
* **is_zero: **This integer is a flag that is set to 1 if the '0' flag is specified in the format string. This flag is used to determine whether to pad with zeros or spaces.
* **is_minus:** This integer is a flag that is set to 1 if the '-' flag is specified in the format string. This flag is used to determine whether to left-align the output.
* **is_dot:** This integer is a flag that is set to 1 if the '.' flag is specified in the format string. This flag is used to determine whether a precision was specified in the format string.

**By using this struct,** we can easily keep track of all the relevant information about the format string and the corresponding arguments in a single object. This makes it easier to handle the different conversion specifiers and flags, as we can access all the necessary information in a uniform way.

_va_list  args;_ is **WRONG HERE** ! 



**DAY 3 PROGRESS**: make the flag work 

I didn't make any progress… 

**DAY 4 PROGRESS:** learn how struct works:

I added a putnumber function to see if the conversion works, It goes on timeout because the function is recursive;

Next I will start to approach the hexadecimals world to do the pointer conversion and print the memory address, and then add the '%%' conversion.

**Made little to no progress with implementing the bonus**.



<p id="gdcalert2" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image2.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert3">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image2.png "image_tooltip")


**DAY 5 PROGRESS:**

I am using printf inside the function to try debug the code, it seems like  there is a issue on how I am using the struct: 


```
It looks like there's an issue with how the width value is being stored and accessed in the struct.

Based on the printf outputs you provided, it seems that the width value is correctly initialized to 0, but is not being properly updated by the width flag function. The printf output inside the flag function shows that the width value is being set correctly to the value of the digit after the % sign, but the printf output inside the placeholder function shows that the width value is being accessed incorrectly as 25 instead of 5.

One possible explanation for this issue is that there may be multiple instances of the tdata struct being created and modified, and the version being accessed inside the placeholder function may not be the same as the one being modified inside the width flag function.

To fix this issue, you may want to check that there is only one instance of the tdata struct being created and passed around, and that any modifications made to it in one part of the code are reflected in other parts of the code that access it. It may also be helpful to add more printf statements to track the value of the width variable at different stages of the code to better understand where the issue is occurring.
```


THE struct is now working but everything else  not.. 

**DAY 6 PROGRESS: **

I realized the approach was wrong, so I created a function called "check_flags" that does all the checks I need and updates the struct.

I checked if the struct was being updated correctly using various printf inside the function call. 

After that I modified the test.c function to do more testing and now I need to create a function called "do_flags" that prints out what I need to correctly format the output.** **

**DAY 7 PROGESS:**

I have splitted the check_flags  function into two smaller  functions to check separately the sign flags and  the formatting  flags. Since the formatting  flags are harder to implement.



<p id="gdcalert3" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image3.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert4">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image3.png "image_tooltip")


**DAY 8 PROGRESS:**

I tested the little progress I made earlier and I found out that there is something working, 



  
