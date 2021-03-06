/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:54:30 by agundry           #+#    #+#             */
/*   Updated: 2017/08/01 17:15:45 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	formatting_d(t_buf *buf, t_format *fmt, char *arg, size_t arglen)
{
	fmt->f_sharp = 0;
	int_format_intro(fmt, arg, &arglen);
	if (fmt->f_zero)
		int_sign(buf, fmt, arg);
	if (fmt->f_minus == 0)
		int_padding(buf, fmt, arglen, arg[0]);
	if (fmt->f_zero == 0)
		int_sign(buf, fmt, arg);
	int_precision(buf, fmt, (ft_isdigit(arg[0])) ? arglen : arglen - 1);
	if (!ft_isdigit(arg[0]))
		ft_buf_add(buf, arg + 1, arglen - 1);
	else
		ft_buf_add(buf, arg, arglen);
	if (fmt->f_minus == 1)
		int_padding(buf, fmt, arglen, arg[0]);
	return (1);
}

int			conv_d(t_buf *buf, t_format *fmt, va_list vl)
{
	char	*arg;

	if (fmt->len_mod == '\0')
		arg = ft_stoa_base(va_arg(vl, int), 10);
	else if (fmt->len_mod == 'H')
		arg = ft_stoa_base((signed char)va_arg(vl, int), 10);
	else if (fmt->len_mod == 'h')
		arg = ft_stoa_base((short)va_arg(vl, int), 10);
	else
		arg = ft_stoa_base(va_arg(vl, long), 10);
	if (!arg)
		exit_printf(5);
	formatting_d(buf, fmt, arg, ft_strlen(arg));
	free(arg);
	return (1);
}
