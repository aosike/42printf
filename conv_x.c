/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:55:23 by agundry           #+#    #+#             */
/*   Updated: 2017/10/08 15:29:28 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strtoupper(char *arg)
{
	char	*c;

	c = arg;
	while (*c)
	{
		*c = ft_toupper(*c);
		c++;
	}
	return (arg);
}

static int	formatting_x(t_buf *buf, t_format *fmt, char *arg, size_t arglen)
{
	int_format_intro(fmt, arg, &arglen);
	if (fmt->f_minus == 0 && fmt->f_zero == 0)
		int_padding(buf, fmt, (fmt->f_sharp) ? arglen + 2 : arglen, arg[0]);
	if (fmt->conv == 'p')
		ft_buf_add(buf, "0x", 2);
	else if (fmt->f_sharp && ft_strcmp("0", arg))
		ft_buf_add(buf, (fmt->conv == 'X') ? "0X" : "0x", 2);
	if (fmt->f_minus == 0 && fmt->f_zero == 1)
		int_padding(buf, fmt, (fmt->f_sharp) ? arglen + 2 : arglen, arg[0]);
	int_precision(buf, fmt, arglen);
	ft_buf_add(buf, arg, arglen);
	if (fmt->f_minus == 1)
		int_padding(buf, fmt, (fmt->f_sharp) ? arglen + 2 : arglen, arg[0]);
	return (0);
}

int			conv_x(t_buf *buf, t_format *fmt, va_list vl)
{
	char	*arg;

	if (fmt->len_mod == '\0')
		arg = ft_utoa_base(va_arg(vl, unsigned), 16);
	else if (fmt->len_mod == 'H')
		arg = ft_utoa_base((unsigned char)va_arg(vl, uintmax_t), 16);
	else if (fmt->len_mod == 'h')
		arg = ft_utoa_base((unsigned short)va_arg(vl, unsigned), 16);
	else
		arg = ft_utoa_base(va_arg(vl, unsigned long), 16);
	if (!arg)
		exit_printf(8);
	if (fmt->conv == 'X')
		arg = ft_strtoupper(arg);
	formatting_x(buf, fmt, arg, ft_strlen(arg));
	free(arg);
	return (1);
}

int			conv_p(t_buf *buf, t_format *fmt, va_list vl)
{
	char	*arg;

	arg = ft_utoa_base((unsigned long long)va_arg(vl, void*), 16);
	if (!arg)
		exit_printf(9);
	fmt->f_sharp = 1;
	formatting_x(buf, fmt, arg, ft_strlen(arg));
	free(arg);
	return (1);
}
