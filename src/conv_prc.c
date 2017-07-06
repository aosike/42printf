int	conv_prc(char buf[BUFF_SIZE], t_format *fmt, va_list vl)
{
	(void)ap;
	fmt->prec = -1;
	if (fmt->min_width > 1 && fmt->f_minus == 0)
		str_formatting(buf, fmt, 1);
	buf_add(buf, &(char){'%'}, 1); // ????????????
	if (fmt->min_width > 1 && fmt->f_minus == 1)
		str_formatting(buf, fmt, 1);
	return (1);
}
