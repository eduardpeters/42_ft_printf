/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:21:40 by epeters-          #+#    #+#             */
/*   Updated: 2022/07/15 17:18:15 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_string(char *s)
{
	if (s)
	{	
		ft_putstr(s);
		return (ft_strlen(s));
	}
	return (ft_printf("(null)"));
}
