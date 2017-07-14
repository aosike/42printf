int	ft_printf(const char *format, ...)
{
	char	*str;
	int		ret;
	va_list	vl;

	va_start(vl, format);
	if ((ret = ft_printf_core((char*)format, vl, &str)) < 0)
		return (-1);
	va_end(ap);
	write(1, str, ret);
	free(str);
	return (ret);
}

int	ft_printf_core(char *format, va_list ap, char **ret)
{
	t_format	fmt;
	char		buf[BUFF_SIZE];
	char		*per;

	while ((per = ft_strchr(format, '%')) != NULL)
	{
		ft_bzero(&fmt, sizeof(fmt));
		ft_bzero(&buf, BUFF_SIZE); //?
		format = parse_fmt(per + 1, &fmt);
		if (fmt.conv != '\0')
			if (tables_dispatch(buf, &fmt, ap) == -1)
				return (cleanup_buf(&buf));
	}
	if (*format != '\0')
		ft_buffer_add(&b, format, ft_strlen(format));
	*ret = b.str;
	return ((int)ft_strlen(buf)); //?
}

int	tables_dispatch(char buf[BUFF_SIZE], t_format *fmt, va_list vl)
{
	static char	*spec = "csCSdouxXp%";
	static t_fc	fp[11];
	size_t		i;

	fp[0] = &conv_c;
	fp[1] = &conv_s;
	fp[2] = &conv_wc;
	fp[3] = &conv_wcs;
	fp[4] = &conv_d;
	fp[5] = &conv_o;
	fp[6] = &conv_u;
	fp[7] = &conv_x;
	fp[8] = &conv_x;
	fp[9] = &conv_p;
	fp[10] = &conv_prc;
	i = 0;
	while (spec[i] != fmt->conv)
		++i;
	return (fp[i](b, fmt, ap));
}

char	*parse_fmt(char *format, t_format *fmt)
{
	if (*format == '\0')
		return (format);
	format = parse_flags(format, fmt);
	format = parse_min_width(format, fmt);
	format = parse_precision(format, fmt);
	format = parse_len_mod(format, fmt);
	if (parse_conv(*format, fmt) == 0)
		return (format);
	return (format + 1);
}
