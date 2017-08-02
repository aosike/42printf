/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:54:56 by agundry           #+#    #+#             */
/*   Updated: 2017/08/01 16:54:59 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formatting_o(t_buf *buf, t_format *fmt, char *arg, size_t arglen)
{
	int_format_intro(fmt, arg, &arglen); ////////////
	if (fmt->f_minus == 0)
		int_padding(buf, fmt, (fmt->f_sharp) ? arglen + 1 : arglen, arg[0]);
	if (fmt->f_sharp && (!ft_strequ("0", arg) || fmt->prec == 0))
		ft_buf_add(buf, "0", 1);
	int_precision(buf, fmt, (fmt->f_sharp) ? arglen + 1 : arglen);
	ft_buf_add(buf, arg, arglen);
	if (fmt->f_minus == 1)
		int_padding(buf, fmt, (fmt->f_sharp) ? arglen + 1 : arglen, arg[0]);
	return (1);
}

static int	formatting_u(t_buf *buf, t_format *fmt, char *arg, size_t arglen)
{
	fmt->f_sharp = 0;
	fmt->f_space = 0;
	fmt->f_plus = 0;
	return(formatting_o(buf, fmt, arg, arglen));
}

int			conv_u(t_buf *buf, t_format *fmt, va_list vl)
{
	char	*arg;

	if (fmt->len_mod == '\0')
		arg = ft_utoa_base(va_arg(vl, unsigned), 10); ///////////////
	else if (fmt->len_mod == 'H')
		arg = ft_utoa_base((unsigned char)va_arg(vl, unsigned), 10); ////////////
	else if (fmt->len_mod == 'h')
		arg = ft_utoa_base((unsigned short)va_arg(vl, unsigned), 10); ////////////
	else
		arg = ft_utoa_base(va_arg(vl, unsigned long), 10); ////////////
	if (!arg)
		exit_printf(6); /////////////?????????????????/
	formatting_u(buf, fmt, arg, ft_strlen(arg));
	free(arg);
	return (1);	
}

int			conv_o(t_buf *buf, t_format *fmt, va_list vl)
{
	char	*arg;

	if (fmt->len_mod == '\0')
		arg = ft_utoa_base(va_arg(vl, unsigned), 8);
	else if (fmt->len_mod == 'H')
		arg = ft_utoa_base((unsigned char)va_arg(vl, unsigned), 8);
	else if (fmt->len_mod == 'h')
		arg = ft_utoa_base((unsigned short)va_arg(vl, unsigned), 8);
	else
		arg = ft_utoa_base(va_arg(vl, unsigned long), 8);
	if (!arg)
		exit_printf(7);
	formatting_o(buf, fmt, arg, ft_strlen(arg));
	free(arg);
	return (1);
}
