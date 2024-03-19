/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:49:25 by mrechuli          #+#    #+#             */
/*   Updated: 2024/03/19 17:08:41 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

// int main(void)
// {
//     char c = '&';
//     printf("; Dlugosc stringu \"%c\": %d\n", c, print_char(c));
//     return (0);
// }