/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:16:30 by aperron           #+#    #+#             */
/*   Updated: 2023/11/02 16:37:40 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		nb_chars;
	int		index;
	int		to_interpret;
	va_list	args;

	to_interpret = 0;
	nb_chars = 0;
	index = 0;
	va_start(args, str);
	while (str[index] != '\0')
	{
		if (str[index] == '%')
			to_interpret = 1;
		else if (to_interpret == 1)
		{
			determine_output(str[index], args, &nb_chars);
			to_interpret = 0;
		}
		else
			write_output_char(str[index], &nb_chars);
		index++;
	}
	va_end(args);
	return (nb_chars);
}

int	main(int argc, char const *argv[])
{
	printf("Nb chars: %i\n", ft_printf("1%%2%c34\n", 'i', "MA"));
	return (0);
}
