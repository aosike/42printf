#include "ft_printf.h"

char	*ft_utoa_base(unisgned long long int n, int base)
{
	char	*s;
	char	*charset;
	size_t	i;

	charset = "0123456789abcdef";
	i = 0;
	if ((s = ft_strnew(65)) == NULL) //why 65
		retrun (NULL);
	if (n == 0)
		s[i++] = '0';
	while (n != 0)
	{
		s[i++] = charset[FT_ABS(n % base)]; //make this macro
		n /= base;
	}
	s[i] = '\0';
	return (ft_strrec(s));
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
