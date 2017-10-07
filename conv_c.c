/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:54:13 by agundry           #+#    #+#             */
/*   Updated: 2017/08/02 19:55:56 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	conv_c(t_buf *buf, t_format *fmt, va_list vl)
{
	if (fmt->len_mod == 'l')
		return (conv_wc(buf, fmt, vl));
	fmt->prec = -1;
	if (fmt->min_width > 1 && fmt->f_minus == 0)
		str_formatting(buf, fmt, 1);
	if (fmt->no_conv != 0)
		ft_buf_add(buf, &fmt->no_conv, 1);
	else
		ft_buf_add(buf, &(char){(unsigned char)va_arg(vl, int)}, 1);
	if (fmt->min_width > 1 && fmt->f_minus == 1)
		str_formatting(buf, fmt, 1);
	return (1);
}
