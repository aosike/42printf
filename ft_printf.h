#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <limits.h>
# include "libft.h"

# define SPECIFIERS "csCSdouxXp%"
# define FT_ABS(x) (((x) < 0) ? -(x) : (x))
# define FT_MAX(a, b) ((a) < (b) ? (b) : (a))
# define FT_BUF_FREE(b) (free((b)->str))

# ifndef MB_LEN_MAX
#  define MB_LEN_MAX 4
# endif
# ifndef BUFF_SIZE			//
#  define BUFF_SIZE 1024 	//
# endif

typedef struct		s_format
{
	char			*str;
	unsigned int	f_sharp: 1;
	unsigned int	f_zero: 1;
	unsigned int	f_minus: 1;
	unsigned int	f_space: 1;
	unsigned int	f_plus: 1;
	unsigned int	min_width;
	int				prec;
	char			len_mod;
	char			conv;
	char			no_conv;
}					t_format;

typedef int			(*t_fc)(t_buf*, t_format*, va_list);

/*ft_printf_core.c*/
int					ft_printf(const char *format, ...);
int					ft_printf_core(char*format, va_list ap, char **ret);
int					tables_dispatch(t_buf *buf, t_format *fmt, va_list vl);
char				*parse_fmt(char *format, t_format *fmt);

/*parsing.c*/
char				*parse_flags(char *format, t_format *fmt);
char				*parse_min_width(char *format, t_format *fmt);
char				*parse_precision(char *format, t_format *fmt); // add * functionality here, ask robin
char				*parse_len_mod(char *format, t_format *fmt);
int					parse_conv(char c, t_format *fmt);

/*str_formatting.c*/
//static size_t		get_padding(size_t len, unsigned mw, int prec);
int					str_formatting(t_buf *buf, t_format *fmt, size_t arglen);

/*int_formatting.c*/
int					int_format_intro(t_format *fmt, char *arg, size_t *arglen);
int					int_padding(t_buf *buf, t_format *fmt, size_t arglen, int fchar);
int					int_sign(t_buf *buf, t_format *fmt, char *arg);
int					int_precision(t_buf *buf, t_format *fmt, size_t arglen);

/*utf8.c*/
int					ft_wctomb(char *s, wchar_t wchar);
size_t				ft_wcstombs(char *s, wchar_t *pwcs, size_t n);
size_t				ft_wcslen(const wchar_t *s);
int					conv_to_utf8(int wbytes, wchar_t wchar, char *s);

/*ft_xtoa_base.c*/
char				*ft_strrev(char *str);
char				*ft_utoa_base(unsigned long long int n, int base);
char				*ft_stoa_base(long long int n, int base);

/*conv_c.c*/
int					conv_c(t_buf *buf, t_format *fmt, va_list vl);

/*conv_d.c*/
//static int			formatting_d(t_buf *buf, t_format *fmt, char *arg, size_t arglen);
int					conv_d(t_buf *buf, t_format *fmt, va_list vl);

/*conv_prc.c*/
int					conv_prc(t_buf *buf, t_format *fmt, va_list vl);

/*conv_s.c*/
int					conv_s(t_buf *buf, t_format *fmt, va_list vl);

/*conv_uo.c*/
//static int			formatting_o(t_buf *buf, t_format *fmt, char *arg, size_t arglen);
//static int			formatting_u(t_buf *buf, t_format *fmt, char *arg, size_t arglen);
int					conv_u(t_buf *buf, t_format *fmt, va_list vl);
int					conv_o(t_buf *buf, t_format *fmt, va_list vl);

/*conv_wc.c*/
int					conv_wc(t_buf *buf, t_format *fmt, va_list vl);

/*conv_wcs.c*/
int					conv_wcs(t_buf *buf, t_format *fmt, va_list vl);

/*conv_x.c*/
char				*ft_strtoupper(char *arg);
//static int			formatting_x(t_buf *buf, t_format *fmt, char *arg, size_t arglen);
int					conv_x(t_buf *buf, t_format *fmt, va_list vl);
int					conv_p(t_buf *buf, t_format *fmt, va_list vl);

/*utils.c*/
void				exit_printf(int code);
int					cleanup_buf(t_buf *pb);
#endif
