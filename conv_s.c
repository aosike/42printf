/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:54:45 by agundry           #+#    #+#             */
/*   Updated: 2017/08/01 16:54:48 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	conv_s(t_buf *buf, t_format *fmt, va_list vl)
{
	char	*arg;
	size_t	arglen;

	if (fmt->len_mod == 'l')
		return (conv_wcs(buf, fmt, vl));
	arg = va_arg(vl, char*);
	if (arg == NULL)
		arg = "(null)";
	arglen = ft_strlen(arg);
	if (fmt->min_width > 0 && fmt->f_minus == 0)
		str_formatting(buf, fmt, arglen);
	if (fmt->prec > -1 && (size_t)fmt->prec < arglen)
		arglen = fmt->prec;
	ft_buf_add(buf, arg, arglen);
	if (fmt->min_width > 0 && fmt->f_minus == 1)
		str_formatting(buf, fmt, arglen);
	return (1);
}
