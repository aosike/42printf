#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	char	*str;
	int		ret;
	va_list	vl;

	va_start(vl, format);
	if ((ret = ft_printf_core((char*)format, vl, &str)) < 0)
		return (-1);
	va_end(vl);
	write(1, str, ret);
	free(str);
	return (ret);
}
