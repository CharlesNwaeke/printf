@include "main.h"

/********** PRINT CHAR *******/

/*
 * print_char - prints a char
 * @types: list a of arguments
 * @buffer: Buffer array to handle print
 * @fag: calculate active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(typs, int);
