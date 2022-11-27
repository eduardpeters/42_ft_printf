/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:44:09 by epeters-          #+#    #+#             */
/*   Updated: 2022/07/17 18:24:51 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_get_u_n_size(unsigned int n)
{
	size_t	size;

	size = 2;
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_u_itoa(unsigned int n)
{
	size_t	size;
	char	*str;

	size = ft_get_u_n_size(n);
	str = (char *)(malloc(sizeof(*str) * size));
	if (!str)
		return (NULL);
	str[size - 1] = '\0';
	size -= 2;
	while (size > 0)
	{
		str[size] = '0' + (n % 10);
		n = n / 10;
		size--;
	}
	str[size] = '0' + (n % 10);
	return (str);
}

int	ft_print_int(int n)
{
	char	*int_str;
	int		print_count;

	if (n == 0)
		return (ft_print_char('0'));
	int_str = ft_itoa(n);
	if (!int_str)
		return (0);
	print_count = ft_print_string(int_str);
	free(int_str);
	return (print_count);
}

int	ft_print_u_int(unsigned int n)
{
	char	*u_int_str;
	int		print_count;

	if (n == 0)
		return (ft_print_char('0'));
	u_int_str = ft_u_itoa(n);
	if (!u_int_str)
		return (0);
	print_count = ft_print_string(u_int_str);
	free(u_int_str);
	return (print_count);
}
