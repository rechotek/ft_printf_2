/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:22:50 by mrechuli          #+#    #+#             */
/*   Updated: 2024/03/19 17:29:07 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "print_char.c"
// #include "print_string.c"
// #include "print_pointer.c"
// #include "print_int.c"
// #include "print_unsigned_int.c"
// #include "print_hex.c"

// static int	check_type(const char *in, va_list *args)
// {
// 	int	x;

// 	x = 0;
// 	if (*in == 'c')
// 		x += print_char(va_arg(*args, int));
// 	else if (*in == 's')
// 		x += print_string(va_arg(*args, char *));
// 	else if (*in == 'p')
// 		x += print_pointer(va_arg(*args, unsigned long long), 87);
// 	else if (*in == 'd')
// 		x += print_int(va_arg(*args, int));
// 	else if (*in == 'i')
// 		x += print_int(va_arg(*args, int));
// 	else if (*in == 'u')
// 		x += print_unsigned_int(va_arg(*args, unsigned int));
// 	else if (*in == 'x')
// 		x += print_hex(va_arg(*args, unsigned int), 87);
// 	else if (*in == 'X')
// 		x += print_hex(va_arg(*args, unsigned int), 55);
// 	return (x);
// }

// int	ft_printf(const char *input, ...)
// {
// 	va_list			args;
// 	unsigned int	x;

// 	x = 0;
// 	va_start(args, input);
// 	while (*input != '\0')
// 	{
// 		if (*input == '%')
// 		{
// 			input++;
// 			if (ft_strchr("cspdiuxX", *input))
// 				x += check_type(input, va_arg(args, void *));
// 			else if (*input == '%')
// 				x += print_char('%');
// 		}
// 		else
// 			x = x + print_char(*input);
// 		input++;
// 	}
// 	va_end(args);
// 	return (x);
// }

static int	check_type(const char *in, va_list args)
{
    int	x;

    x = 0;
    if (*in == 'c')
        x += print_char(va_arg(args, int));
    else if (*in == 's')
        x += print_string(va_arg(args, char *));
    else if (*in == 'p')
        x += print_pointer(va_arg(args, unsigned long), 87);
    else if (*in == 'd')
        x += print_int(va_arg(args, int));
    else if (*in == 'i')
        x += print_int(va_arg(args, int));
    else if (*in == 'u')
        x += print_unsigned_int(va_arg(args, unsigned int));
    else if (*in == 'x')
        x += print_hex(va_arg(args, unsigned int), 87);
    else if (*in == 'X')
        x += print_hex(va_arg(args, unsigned int), 55);
    return (x);
}

int	ft_printf(const char *input, ...)
{
    va_list			args;
    unsigned int	x;

    x = 0;
    va_start(args, input);
    while (*input != '\0')
    {
        if (*input == '%')
        {
            input++;
            if (ft_strchr("cspdiuxX", *input))
                x += check_type(input, args);
            else if (*input == '%')
                x += print_char('%');
        }
        else
            x = x + print_char(*input);
        input++;
    }
    va_end(args);
    return (x);
}

// int main(void) {
//    	char c = 'A';
//     char *s = "1236";
//     unsigned long p = (unsigned long)s;
//     int d = -123;
//     int i = 456;
//     unsigned int u = 789;
//     unsigned int x = 1236;
//     unsigned int X = 11;

//     ft_printf("Character: %c\n", c);
//     ft_printf("String: %s\n", s);
//     ft_printf("Pointer: %p\n", p);
//     ft_printf("Signed decimal: %d\n", d);
//     ft_printf("Signed integer: %i\n", i);
//     ft_printf("Unsigned integer: %u\n", u);
//     ft_printf("Hexadecimal (lowercase): %x\n", x);
//     ft_printf("Hexadecimal (uppercase): %X\n", X);

//     return (0);
// }


// int	check_type(va_list args, const char format)
// {
// 	int	x;

// 	x = 0;
// 	if (format == 'c')
// 		x += print_char(va_arg(args, int));
// 	else if (format == 's')
// 		x += print_string(va_arg(args, char *));
// 	else if (format == 'p')
// 		x += print_pointer(va_arg(args, unsigned long long), 87);
// 	else if (format == 'd')
// 		x += print_int(va_arg(args, int));
// 	else if (format == 'i')
// 		x += print_int(va_arg(args, int));
// 	else if (format == 'u')
// 		x += print_unsigned_int(va_arg(args, unsigned int));
// 	else if (format == 'x')
// 		x += print_hex(va_arg(args, unsigned int), format);
// 	else if (format == 'X')
// 		x += print_hex(va_arg(args, unsigned int), format);
// 	return (x);
// }