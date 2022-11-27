/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:39:42 by epeters-          #+#    #+#             */
/*   Updated: 2022/07/17 18:24:39 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_get_n_size(unsigned long n)
{
	size_t	size;

	size = 2;
	while (n > 15)
	{
		n = n / 16;
		size += 1;
	}
	return (size);
}

static char	*ft_ptrtoa(unsigned long n, const char *base)
{
	size_t	size;
	char	*str;

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

int	ft_print_ptr(unsigned long n)
{
	char	*ptr_str;
	int		print_count;

	print_count = 0;
	ptr_str = ft_ptrtoa(n, "0123456789abcdef");
	if (!ptr_str)
		return (0);
	print_count += ft_print_string("0x");
	print_count += ft_print_string(ptr_str);
	free(ptr_str);
	return (print_count);
}
