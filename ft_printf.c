/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:58:37 by marvin            #+#    #+#             */
/*   Updated: 2023/12/14 15:58:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

const char	*ft_write_text(const char *cible)
{
	int 	i;
	char	*s;
	
	i = 0;
	s = (char *)cible;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '%')
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return ((const char *) s + i);
}

int ft_search_data_type(const char *cible, va_list args)
{
	int	i;
	
	if (*cible == 'c')
	{
		c = va_arg(args, char);
		ft_putchar_fd(i, 1);
		i = 1
	}
	else if (*cible == 'd')
		i = ft_if_decimal(args);
	else if (*cible == 's')
		i = ft_if_string(args);
	else if (*cible == 'x')
		i = ft_if_hexa(args);
	else if (*cible == 'X')
		i = ft_if_hexa_up(args);
	else if (*cible == '%')
	{
		ft_putchar_fd('%', 1);
		i = 1;
	}
	else if (*cible == 'p')
		
	return (i);
}


int	ft_printf(const char *cible, ...)
{
	
	va_list args;
	
	va_start(args, cible);
	if (*cible == '"')
		cible = cible + 1;
	// à revoir, pas de gestion par la fonction printf des cas où l'arg 1 n'a pas de guillemet
	else 
		write(1, "(null)", 6);
		return (0);
	while (*cible && *cible != '"')
	{
		if(*cible == '%')
			ft_search_data_type(cible + 1, args);
		else if(*cible != '%')
			cible = ft_write_text(cible);
		else
		{
			write (1, "(null)", 6);
			va_end(args);
		}
	}
	va_end(args);
	return (0);
}

int print_if_number()
{
	return(6785);
}


char *write_text()
{
char *s = "";
return s;
}

void main()
{
	printf(" %s", write_text());
}
