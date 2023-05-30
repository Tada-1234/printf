#include "main.h"

<<<<<<< HEAD
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, counter = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			counter++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			counter += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (counter);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
/**
*_printf - Print a formatted string
*@format: format string
*Return: number of characters printed
*/
int _printf(const char *format, ...)
{
int count = 0;
va_list list;
char *pointer, *start;
param_func flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
va_start(list, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (pointer = (char *)format; *pointer; pointer++)
{
init_params(&flags, list);
if (*pointer != '%')
{
count += _putchar(*pointer);
continue;
}
start = pointer;
pointer++;
while (get_flags(pointer, &flags))
{
pointer++;
}
pointer = get_width(pointer, &flags, list);
pointer = get_precision(pointer, &flags, list);
if (get_mods(pointer, &flags))
pointer++;
if (!func_parse(pointer))
count += print_range(start, pointer,
flags.l_mod || flags.h_mod ? pointer - 1 : 0);
else
count += print_func(pointer, list, &flags);
}
_putchar(-1);
va_end(list);
return (count);
>>>>>>> 71b4b1c27a78712d08b440800529535eb12d0c4c
}
