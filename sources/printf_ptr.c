/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:36:32 by jlebard           #+#    #+#             */
/*   Updated: 2023/12/20 16:36:41 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_write_ptr(uintptr_t ptr)
{
	unsigned long long		i;
	unsigned long long		n;
	char					*dest;
	char					*base_hexa;

	i = 0;
	n = (unsigned long long)ptr;
	dest = malloc(sizeof(char) * (n / 16 + 2));
	base_hexa = "0123456789abcdef";
	while (ptr > 0)
	{
		dest[i] = base_hexa[n % 16];
		n /= 16;
		i ++;
	}
	dest[i] = '\0';
	n = i + 1;
	while (i-- >= 0)
		ft_putchar_fd(dest[i], 1);
	free(dest);
	return ((int)n);
}

int	ft_if_ptr(void *ptr)
{
	uintptr_t	n;

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
