/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:39:25 by agundry           #+#    #+#             */
/*   Updated: 2017/10/31 13:39:27 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	char	*str;
	int		ret;
	va_list	vl;

	va_start(vl, format);
	if ((ret = ft_printf_core((char*)format, vl, &str)) < 0)
		return (-1);
	va_end(vl);
	write(1, str, ret);
	free(str);
	return (ret);
}
