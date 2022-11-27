/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:33:49 by epeters-          #+#    #+#             */
/*   Updated: 2022/07/15 17:18:07 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_percent(void)
{
	ft_putchar('%');
	return (1);
}

int	ft_print_char(const char c)
{
	ft_putchar(c);
	return (1);
}
