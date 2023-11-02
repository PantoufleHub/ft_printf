/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:40:49 by aperron           #+#    #+#             */
/*   Updated: 2023/11/02 16:35:26 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_output_char(char c, int *counter)
{
	write(0, &c, 1);
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

char	*int_to_hexa(int nb)
{
	char	*hexa;
	char	*base;

	base = "0123456789ABCDEF";
	return (hexa);
}

void	write_number(long nb, int *counter)
{
}

void	determine_output(char format, va_list args, int *counter)
{
	if (format == '%')
		write_output_char('%', counter);
	if (format == 'c')
		write_output_char(va_arg(args, int), counter);
	if (format == 's')
		write_string(va_arg(args, char *), counter);
}
