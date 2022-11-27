/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:56:14 by epeters-          #+#    #+#             */
/*   Updated: 2022/07/19 17:30:45 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	conversion_router(char conv, va_list args)
{
	int	print_count;

	print_count = 0;
	if (conv == '%')
		print_count += ft_print_percent();
	else if (conv == 'c')
		print_count += ft_print_char(va_arg(args, int));
	else if (conv == 's')
		print_count += ft_print_string(va_arg(args, char *));
	else if (conv == 'i' || conv == 'd')
		print_count += ft_print_int(va_arg(args, int));
	else if (conv == 'u')
		print_count += ft_print_u_int(va_arg(args, unsigned int));
	else if (conv == 'x' || conv == 'X')
		print_count += ft_print_hex(va_arg(args, unsigned int), conv);
	else if (conv == 'p')
		print_count += ft_print_ptr(va_arg(args, unsigned long));
	return (print_count);
}

int	ft_printf(char const *string, ...)
{
	int		print_count;
	va_list	args;

	print_count = 0;
	va_start(args, string);
	if (!string)
		return (print_count);
	while (*string)
	{
		if (*string == '%')
			print_count += conversion_router(*(++string), args);
		else
		{
			ft_putchar(*string);
			print_count++;
		}
		string++;
	}
	va_end(args);
	return (print_count);
}
