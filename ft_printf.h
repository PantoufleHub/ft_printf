/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:01:00 by aperron           #+#    #+#             */
/*   Updated: 2023/11/03 16:06:16 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);

void	write_output_char(char c, int *counter);

void	write_string(char *c, int *counter, int to_free);

char	*long_hexa(unsigned long long nb, char *base);

void	write_number(long n, int *counter);

void	determine_output(char format, va_list args, int *counter);

void	reverse_string(char *str);

void	write_pointer(void *p, int *counter);

#endif