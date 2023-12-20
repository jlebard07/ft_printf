/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:46:56 by jlebard           #+#    #+#             */
/*   Updated: 2023/12/20 16:36:34 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_if_hexa_down(int n)
{
	int		i;
	char	*dest;
	char	*base_hexa;

	i = 0;
	if (n < 0)
	{
		write(1, '-', 1);
		ft_if_hexa_down(-n);
	}
	dest = malloc(sizeof(char) * (n / 16 + 2));
	base_hexa = "0123456789ABCDEF";
	while (n > 0)
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
	return (n);
}
