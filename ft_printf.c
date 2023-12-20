/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:20:49 by jlebard           #+#    #+#             */
/*   Updated: 2023/12/20 16:36:05 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
// #include <stdio.h>

static int	ft_write_data_type(char *cible, va_list args)
{
	int	i;

	if (*cible == 'c')
	{
		ft_putchar_fd(va_arg(args, char), 1);
		return (1);
	}
	else if (*cible == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (*cible == 'd' || *cible == 'i')
		return (ft_if_decimal(va_arg(args, int)));
	else if (*cible == 's')
		return (ft_if_string(va_arg(args, char *)));
	else if (*cible == 'x')
		return (ft_if_hexa_down(va_arg(args, int)));
	else if (*cible == 'X')
		return (ft_if_hexa_up(va_arg(args, int)));
	else if (*cible == 'p')
		return (ft_if_ptr(va_arg(args, void *)));
	else if (*cible == 'u')
		return (ft_if_unsigned(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *cible, ...)
{
	va_list	args;
	int		len;

	if (!cible)
	{
		write(1, "(null)", 6);
		return (0);
	}
	va_start(args, cible);
	len = 0;
	while (*cible)
	{
		if (*cible == '%')
		{
			len += ft_write_data_type((char *)cible + 1, args);
			cible++;
		}
		else if (*cible != '%')
			ft_putchar_fd(*cible, 1);
		len++;
		cible++;
	}
	va_end(args);
	return (len);
}

// int	print_if_number()
// {
// 	int i = 2682162867;
// 	return(i);
// }

// char print_if_char(){char c; c = 'c'; return (c);}

// char *print_if_ptr(){char *s = "huwdih";
// return (s);}

// unsigned int print_if_unsigned(){unsigned int i = 627851825; return (i);}

// int print_if_hexa(){int i = 6217825;return (i);}

// int print_if_hexa_up(){int i = 2682162867;
// 	return(i);
// }

// char *print_if_text()
// {
// char *s = "9dheb";
// return s;
// }

// void main()
// {
// 	ft_printf("mon printf, text : %s\n", print_if_text());
// 	ft_printf("mon printf, char : %c\n", print_if_char());
// 	ft_printf("mon printf, ptr : %p\n", print_if_ptr());
// 	ft_printf("mon printf, hexa : %x\n", print_if_hexa());
// 	ft_printf("mon printf, hexa up : %X\n", print_if_hexa_up());
// 	ft_printf("mon printf, unsigned : %u\n", print_if_unsigned());
// 	printf("vrai printf, text : %s\n", print_if_text());
// 	printf("vrai printf, char : %c\n", print_if_char());
// 	printf("vrau printf, ptr : %p\n", print_if_ptr());
// 	printf("vrai printf, hexa : %x\n", print_if_hexa());
// 	printf("vrai printf, hexa up : %X\n", print_if_hexa_up());
// 	printf("vrai printf, unsigned : %u\n", print_if_unsigned());
// }
