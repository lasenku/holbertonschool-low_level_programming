#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - prints a char argument from a va_list
 * @args: pointer to the va_list holding the argument
 *
 * Return: void
 */
void print_char(va_list *args)
{
	printf("%c", va_arg(*args, int));
}

/**
 * print_int - prints an int argument from a va_list
 * @args: pointer to the va_list holding the argument
 *
 * Return: void
 */
void print_int(va_list *args)
{
	printf("%d", va_arg(*args, int));
}

/**
 * print_float - prints a float argument from a va_list
 * @args: pointer to the va_list holding the argument
 *
 * Return: void
 */
void print_float(va_list *args)
{
	printf("%f", va_arg(*args, double));
}

/**
 * print_string - prints a string argument from a va_list
 * @args: pointer to the va_list holding the argument
 *
 * Return: void
 */
void print_string(va_list *args)
{
	char *s;

	s = va_arg(*args, char *);
	if (s == NULL)
		printf("(nil)");
	else
		printf("%s", s);
}

/**
 * print_all - prints anything, based on a format string
 * @format: a list of types of arguments passed to the function
 * (c: char, i: int, f: float, s: char *, any other char ignored)
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	typedef struct printer
	{
		char type;
		void (*f)(va_list *);
	} printer_t;

	printer_t printers[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};
	va_list args;
	unsigned int i, j;
	char *sep = "";

	va_start(args, format);

	i = 0;
	while (format != NULL && format[i])
	{
		j = 0;
		while (printers[j].type != '\0')
		{
			if (printers[j].type == format[i])
			{
				printf("%s", sep);
				printers[j].f(&args);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");

	va_end(args);
}
