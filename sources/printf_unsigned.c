/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:38:48 by jlebard           #+#    #+#             */
/*   Updated: 2023/12/20 13:23:02 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_unsigned(unsigned int n)
{
	unsigned int	i;

	i = 0;
	dest = malloc(sizeof(char) * (n / 10 + 2));
	base_unsigned = "0123456789";
	while (n > 0)
	{
		dest[i] = base_unsigned[n % 10];
		n /= 10;
		i ++;
	}
	dest[i] = '\0';
	n = i + 1;
	while (i-- >= 0)
		ft_putchar_fd(dest[i], 1);
	free(dest);
	return ((int)n);
}
