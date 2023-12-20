/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:21:07 by jlebard           #+#    #+#             */
/*   Updated: 2023/12/20 16:40:23 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include "libft/libft.h"

int	ft_printf(const char *cible, ...);
int	ft_if_hexa_down(int n);
int	ft_if_hexa_down(int n);
int	ft_if_ptr(void *ptr);
int	ft_if_string(char *s);
int	ft_if_unsigned(unsigned int n);

#endif