/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_prc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:54:38 by agundry           #+#    #+#             */
/*   Updated: 2017/08/01 17:17:59 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	conv_prc(t_buf *buf, t_format *fmt, va_list vl)
{
	(void)vl;
	fmt->prec = -1;
	if (fmt->min_width > 1 && fmt->f_minus == 0)
		str_formatting(buf, fmt, 1);
	ft_buf_add(buf, &(char){'%'}, 1);
	if (fmt->min_width > 1 && fmt->f_minus == 1)
		str_formatting(buf, fmt, 1);
	return (1);
}
