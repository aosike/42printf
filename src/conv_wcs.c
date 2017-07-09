#include "ft_printf.h"

int	conv_wcs(t_buf *buf, t_format *fmt, va_list vl)
{
	char	*arg;
	wchar_t	*wcs;
	size_t	arglenmax;
	size_t	wlen;

	if ((wcs = va_arg(ap, wchar_t*)) == NULL)
		wcs = L"(null)"; //what the fuck is that
	arglenmax = ft_wcslen(wcs) * sizeof(wchar_t) + 1;
	if ((arg = (char*)malloc(arglenmax)) == 0)
		exit_printf(4);
	wlen = (fmt->prec < 0) ? arglenmax : fmt->prec;
	if ((wlen = ft_wcstombs(arg, wcs, wlen)) == (size_t)-1)
		return (-1);
	if (fmt->f_minus == 0)
		str_formatting(buf, fmt, wlen);
	ft_buf_add(buf, arg, wlen);
	if (fmt->min_width > 0 && fmt->f_minus == 1)
		str_formatting(buf, fmt, wlen);
	free(arg);
	return (1);
}
