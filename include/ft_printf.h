/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:55:55 by epeters-          #+#    #+#             */
/*   Updated: 2022/07/17 17:06:21 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "libft.h"

/* ft_printf.c */
int	ft_printf(char const *string, ...);

/* src/char_conv.c */
int	ft_print_percent(void);
int	ft_print_char(char c);

/* src/str_conv.c */
int	ft_print_string(char *s);

/* src/int_conv.c */
int	ft_print_int(int n);
int	ft_print_u_int(unsigned int n);

/* src/hex_conv.c */
int	ft_print_hex(unsigned int n, char conv);

/* src/ptr_conv.c */
int	ft_print_ptr(unsigned long n);

#endif
