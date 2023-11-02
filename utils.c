/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:40:49 by aperron           #+#    #+#             */
/*   Updated: 2023/11/02 19:53:37 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*long_hexa(long n, char *base)
{
	char	*hexa;
	int		index;
	int		is_neg;

	index = 0;
	is_neg = 0;
	hexa = (char *)malloc(sizeof(char) * 13);
	if (n != 0)
	{
		if (n < 0)
			is_neg = 1;
		while (n != 0)
		{
			hexa[index++] = base[math_abs(n) % 16];
			n /= 16;
		}
	}
	else
		hexa[index++] = '0';
	hexa[index] = '\0';
	reverse_string(hexa);
	return (hexa);
}

void	determine_output(char format, va_list args, int *counter)
{
	char	*str;
	
	if (format == '%')
		write_output_char('%', counter);
	if (format == 'c')
		write_output_char(va_arg(args, int), counter);
	if (format == 's')
		write_string(va_arg(args, char *), counter);
	if (format == 'd' || format == 'i')
		write_number(va_arg(args, int), counter);
	if (format == 'u')
		write_number(va_arg(args, unsigned int), counter);
	if (format == 'x')
	{
		str = long_hexa(va_arg(args, unsigned int), "0123456789abcdef");
		write_string(str, counter);
		free(str);
	}
	if (format == 'X')
	{
		str = long_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
		write_string(str, counter);
		free(str);
	}
	if (format == 'p')
		write_pointer(va_arg(args, void *), counter);
}

void	reverse_string(char *str)
{
	size_t	length;
	size_t	index;
	char	tmp;

	length = 0;
	while (str[length] != '\0')
		length++;
	index = 0;
	while (index < length / 2)
	{
		tmp = str[index];
		str[index] = str[length - index - 1];
		str[length - index - 1] = tmp;
		index++;
	}
}

long	math_abs(long n)
{
	if (n >= 0)
		return (n);
	return (-n);
}
