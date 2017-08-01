#include "ft_printf.h"

int	conv_prc(t_buf *buf, t_format *fmt, va_list vl)
{
	(void)vl;
	fmt->prec = -1;
	if (fmt->min_width > 1 && fmt->f_minus == 0)
		str_formatting(buf, fmt, 1);
	ft_buf_add(buf, &(char){'%'}, 1); // ????????????
	if (fmt->min_width > 1 && fmt->f_minus == 1)
		str_formatting(buf, fmt, 1);
	return (1);
}
