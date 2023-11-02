/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:52:55 by aperron           #+#    #+#             */
/*   Updated: 2023/11/02 19:51:54 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_output_char(char c, int *counter)
{
	write(1, &c, 1);
	*counter += 1;
}

void	write_string(char *str, int *counter)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write_output_char(str[index], counter);
		index++;
	}
}

void	write_number(long n, int *counter)
{
	if (n == 0)
	{
		write_output_char('0', counter);
		return ;
	}
	if (n < 0)
	{
		write_output_char('-', counter);
		n *= -1;
	}
	if (n > 9)
	{
		write_number(n / 10, counter);
		n %= 10;
	}
	if (n <= 9)
	{
		write_output_char(n + '0', counter);
	}
}

void	write_pointer(void *p, int *counter)
{
	char	*str;

	str = long_hexa((long)p, "0123456789abcdef");
	write_string("0x", counter);
	write_string(str, counter);
}
