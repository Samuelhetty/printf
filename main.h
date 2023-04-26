#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1
/**
 * typedef struct Format - Struct op
 *
 * @type: struct format specifier character
 * @Format: The format.
 * @formats: The function associated.
 */
typedef struct Format
{
	char type;
	int (*func_ptr)(va_list, char *, int, int, int, int);
}
Format;


int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int handle_print(const char *format_str, int *ind,
va_list arg, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int print_c(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_s(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list args, char map_n[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int print_ptr(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list arg);
int get_precision(const char *format, int *i, va_list arg);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_rev(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* write handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags, int width, int prec,
	int length, char set, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char set, char extra_c, int set_pad);

int write_unsgnd(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char buffer[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);


#endif
