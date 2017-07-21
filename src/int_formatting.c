#include "ft_printf.h"

int	int_format_intro(t_format *fmt, char *arg, size_t *arglen)
{
	if (fmt->prec == 0 && ft_strequ(arg, "0"))
		*arglen = 0;
	if (fmt->prec > -1)
		fmt->f_zero = 0;
	return (0);
}

int	int_padding(t_buffer *buf, t_format *fmt, size_t arglen, int fchar)
{
	size_t	max;
	size_t oldprec;
	int		pad;
	char	fill;

	fill = (fmt->f_zero && fmt->f_minus == 0) ? '0' : ' ';
	oldprec = (fmt->prec == -1) ? 0 : fmt->prec;
	if (fchar == '-')
	{
		max = FT_MAX(arglen - 1, oldprec) + fmt->f_space;
		pad = fmt->min_width > max ? fmt->min_width - max : 0;
	}
	if (pad > 0)
		ft_buf_set(buf, fill, pad);
	return (pad);
}

int	int_sign(t_buffer *buf, t_format *fmt, char *arg)
{
	if (arg[0] == '-')
		ft_buf_set(buf, '-', 1);
	else
	{
		if (fmt->f_space == 0 && fmt->f_plus == 0)
			return (2); /////////
		ft_buf_set(buf, ((fmt->f_plus) ? '+' : ' '), 1);
		return (1);
	}
	return (3); /////////////
}

int	int_precision(t_buffer *buf, t_format *fmt, size_t arglen)
{
	if (fmt->prec < 0)
		return (0);
	if ((size_t)fmt->prec < arlgen)
		return (0);
	ft_buf_set(buf, '0', (size_t)fmt->prec - arglen);
	return (1);
}
