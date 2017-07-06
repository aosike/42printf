int	conv_c(char buf[BUFF_SIZE], t_format *fmt, va_list vl)
{
	if (fmt->len_mod == 'l')
		return (conv_wc(buf, fmt, vl));
	fmt->prec = -1;
	if (fmt->min_width > 1 && fmt->f_minus == 0)
		str_formatting(buf, fmt, 1);
	if (fmt->no_conv != 0)
		buf_add(buf, &fmt->no_conv, 1);
	else
		buf_add(buf, &(char){(unisigned char)va_arg(vl, int)}, 1); //???????????
	if (fmt->min_width > 1 && fmt->f_minus == 1)
		str_formatting(buf, fmt, 1);
	return (1);
}
