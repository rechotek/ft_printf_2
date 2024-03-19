/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:23:31 by mrechuli          #+#    #+#             */
/*   Updated: 2024/03/19 17:35:58 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
// #include "print_string.c"
// #include "print_char.c"

static char	*create_hex(unsigned int value, int *strlen)
{
	int				x;
	unsigned int	tempvalue;
	char			*str;

	x = 0;
	tempvalue = value;
	while (tempvalue != 0)
	{
		tempvalue = tempvalue / 16;
		x++;
	}
	str = ft_calloc(x + 1, sizeof(char));
	*strlen = x - 1;
	return (str);
}

int	print_hex(unsigned int value, int asc)
{
	unsigned int	tempvalue;
	char			*printout;
	int				x;
	int				*xptr;

	xptr = &x;
	tempvalue = value;
	printout = create_hex(value, xptr);
	if (printout == NULL)
		return (0);
	while (tempvalue != 0 && x-- >= 0)
	{
		if ((tempvalue % 16 < 10))
			printout[x + 1] = (tempvalue % 16) + 48;
		else
			printout[x + 1] = (tempvalue % 16) + asc;
		tempvalue = tempvalue / 16;
	}
	x = ft_strlen(printout);
	ft_putstr_fd(printout, 1);
	free(printout);
	if (value == 0)
		x += print_char('0');
	return (x);
}

// int	main(void)
// {
//     unsigned long	value = 15;
//     int				asc = 87;

//     //int result = print_pointer(value, asc);
// 	printf("; Dlugosc \"%lu\": %d\n", value, print_hex(value, asc));
//     return 0;
// }