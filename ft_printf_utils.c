/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:33:43 by marvin            #+#    #+#             */
/*   Updated: 2023/12/14 15:33:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_if_decimal(va_list args)
{
	int i;
	int n;
	
	n = va_arg(args, int);
	i = 1;
	n = va_arg(args, int);
	ft_putnbr_fd(n, 1);
	if (n < 0)
	{
		i = 2;
		n = -n
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int ft_if_string(va_list args)
{
	char *s;

	s = va_arg(args, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_if_hexa(va_list args)
{
	int		i;
	int 	n;
	char	*dest;
	char	*base_hexa;

	i = 0;
	dest = malloc(sizeof(char) * (n / 16 + 1))
	n = va_arg(args, int);
	base_hexa = "0123456789abcdef";
	while (n > 0)
	{
		dest[i] = base_hexa[n % 16];
		n /= 16; 
		i ++;
	}
	dest[i] = '\0';
	n = i;
	while (i-- >= 0)
		ft_putchar_fd(dest[i], 1);
	free(dest);
	return (n);
}

int	ft_if_hexa_up(va_list args)
{
	int		i;
	int 	n;
	char	*dest;
	char	*base_hexa;

	i = 0;
	dest = malloc(sizeof(char) * (n / 16 + 2))
	n = va_arg(args, int);
	base_hexa = "0123456789ABCDEF";
	while (n > 0)
	{
		dest[i] = base_hexa[n % 16];
		n /= 16; 
		i ++;
	}
	dest[i] = '\0';
	n = i;
	while (i-- >= 0)
		ft_putchar_fd(dest[i], 1);
	free(dest);
	return (n);
}

int	ft_write_ptr(uintptr_t ptr)
{
	int		i;
	int		n;
	char	*dest;
	char	*base_hexa;

	i = 0;
	dest = malloc(sizeof(char) * (n / 16 + 1))
	base_hexa = "0123456789abcdef";
	while (ptr > 0)
	{
		dest[i] = base_hexa[n % 16];
		n /= 16; 
		i ++;
	}
	dest[i] = '\0';
	n = i;
	while (i-- >= 0)
		ft_putchar_fd(dest[i], 1);
	free(dest);
	return (n);
}


int	ft_if_ptr(unsigned long long ptr)
{
	uintptr_t n;

	n = (uintptr_t)ptr;	
	write(1, "0x", 2);
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		return (ft_write_ptr(n));
}

