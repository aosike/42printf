int	conv_s(char buf[BUFF_SIZE], t_format *fmt, va_list vl)
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
	buf_add(buf, arg, arglen);
	if (fmt->min_width > 0 && fmt->f_minus == 1)
		str_formatting(buf, fmt, arglen);
	return (1);
}
