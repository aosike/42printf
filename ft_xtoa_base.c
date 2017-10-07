#include "libftprintf.h"

char	*ft_strrev(char *str)
{
	size_t	half;
	size_t	len;
	size_t	i;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	if (len % 2 == 0)
		half = len / 2;
	else
		half = (len - 1) / 2;
	--len;
	while (i < half)
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i++] = tmp;
	}
	return (str);
}

char	*ft_utoa_base(unsigned long long int n, int base)
{
	char	*s;
	char	*charset;
	size_t	i;

	charset = "0123456789abcdef";
	i = 0;
	if ((s = ft_strnew(65)) == NULL) //why 65
		return (NULL);
	if (n == 0)
		s[i++] = '0';
	while (n != 0)
	{
		s[i++] = charset[FT_ABS(n % base)]; //make this macro
		n /= base;
	}
	s[i] = '\0';
	return (ft_strrev(s));
}

char	*ft_stoa_base(long long int n, int base)
{
	char	*charset;
	char	*s;
	size_t	i;
	int		neg;

	charset = "0123456789abcdef";
	i = 0;
	neg = (n < 0);
	if ((s = ft_strnew(66)) == NULL) //why 66?
		return (NULL);
	if (n == 0)
		s[i++] = '0';
	while (n != 0)
	{
		s[i++] = charset[FT_ABS(n % base)];
		n /= base;
	}
	s[i] = (neg) ? '-' : '\0';
	return (ft_strrev(s));
}
