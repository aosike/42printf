/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:55:08 by agundry           #+#    #+#             */
/*   Updated: 2017/08/01 16:55:10 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	conv_wc(t_buf *buf, t_format *fmt, va_list vl)
{
	char	arg[MB_LEN_MAX + 1];
	size_t	arglen;
	int		wclen;

	if ((wclen = ft_wctomb(arg, va_arg(vl, wint_t))) == -1)
		return (-1);
	arg[wclen] = '\0';
	if ((arglen = ft_strlen(arg)) == 0)
		++arglen;
	fmt->prec = -1;
	if (fmt->min_width > 1 && fmt->f_minus == 0)
		str_formatting(buf, fmt, arglen);
	ft_buf_add(buf, arg, arglen);
	if (fmt->min_width > 1 && fmt->f_minus == 1)
		str_formatting(buf, fmt, arglen);
	return (1);
}
