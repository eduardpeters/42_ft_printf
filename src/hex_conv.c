/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:39:49 by epeters-          #+#    #+#             */
/*   Updated: 2022/07/17 16:39:07 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_get_n_size(unsigned int n)
{
	size_t			size;

	size = 2;
	while (n > 15)
	{
		n = n / 16;
		size += 1;
	}
	return (size);
}

static char	*ft_hextoa(unsigned int n, const char *base)
{
	size_t			size;
	char			*str;

	size = ft_get_n_size(n);
	str = (char *)(malloc(sizeof(*str) * size));
	if (!str)
		return (NULL);
	str[size - 1] = '\0';
	size -= 2;
	while (size > 0)
	{
		str[size] = base[(n % 16)];
		n = n / 16;
		size--;
	}
	str[size] = base[(n % 16)];
	return (str);
}

int	ft_print_hex(unsigned int n, char conv)
{
	char	*hex_str;
	int		print_count;

	print_count = 0;
	if (conv == 'x')
		hex_str = ft_hextoa(n, "0123456789abcdef");
	else
		hex_str = ft_hextoa(n, "0123456789ABCDEF");
	if (!hex_str)
		return (0);
	print_count += ft_print_string(hex_str);
	free(hex_str);
	return (print_count);
}
