# ft_printf
*Because ft_putnbr() and ft_putstr() aren’t enough*

This project is about recoding the <code>printf()</code> function from the libc standard library. Calling the <code>ft_printf()</code> function allows us to format and display text, numbers, and other values.

<p align="center">
  <img width="256" height="256" src="resources/Hotpot_binary_typewriter.png">
</p>

### Function prototype

<code>int ft_printf(const char *, ...)</code>

### Handled convertions

<code>cspdiuxX%</code>

### What is the approach?
1. take a string as a first argument, followed by optional additional arguments for conversion
2. print simple character input
3. if a <code>%</code> is encountered, call the <code>ft_get_param()</code> function to find out what format specifier is used
4. use an appropriate function to handle the format conversion
5. return the total length of the output string
