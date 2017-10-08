/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:47:00 by agundry           #+#    #+#             */
/*   Updated: 2017/02/14 13:58:19 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <limits.h>

# define SPECIFIERS "csCSdouxXp%"
# define FT_ABS(x) (((x) < 0) ? -(x) : (x))
# define FT_MAX(a, b) ((a) < (b) ? (b) : (a))
# define FT_BUF_FREE(b) (free((b)->buf))

//# ifndef MB_LEN_MAX
//#  define MB_LEN_MAX 4
//# endif
# ifndef BUFF_SIZE
#  define BUFF_SIZE 1024
# endif

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buf
{
	char			*buf;
	size_t			blen;
	size_t			bmax;
}					t_buf;

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

t_buf				*ft_buf_init(t_buf *b, size_t size);
t_buf				*ft_buf_add(t_buf *b, char *s, size_t len);
t_buf				*ft_buf_resize(t_buf *b, size_t len);
t_buf				*ft_buf_set(t_buf *b, int c, size_t len);

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *big,
					const char *little, size_t len);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strncat(char *s1, const char *s2, size_t n);

void				*ft_realloc(void *ptr, size_t size, size_t oldsize);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_cntdigits(int n);
int					ft_isspace(int c);
int					ft_cntwrd(const char *s);
void				ft_putstrerror(const char *s);
int					ft_cntwrddelimc(const char *str, char c);
char				*ft_strndup(const char *s1, size_t n);

/*printf*/

/* ft_printf_core.c */
int					ft_printf(const char *format, ...);
int					ft_printf_core(char*format, va_list ap, char **ret);
int					tables_dispatch(t_buf *buf, t_format *fmt, va_list vl);
char				*parse_fmt(char *format, t_format *fmt);

/* parsing.c */
char				*parse_flags(char *format, t_format *fmt);
char				*parse_min_width(char *format, t_format *fmt);
char				*parse_precision(char *format, t_format *fmt);
char				*parse_len_mod(char *format, t_format *fmt);
int					parse_conv(char c, t_format *fmt);

/* str_formatting.c */
int					str_formatting(t_buf *buf, t_format *fmt, size_t arglen);

/* int_formatting.c */
int					int_format_intro(t_format *fmt, char *arg, size_t *arglen);
int					int_padding(t_buf *buf, t_format *fmt, size_t arglen,
		int fchar);
int					int_sign(t_buf *buf, t_format *fmt, char *arg);
int					int_precision(t_buf *buf, t_format *fmt, size_t arglen);

/* utf8.c */
int					ft_wctomb(char *s, wchar_t wchar);
size_t				ft_wcstombs(char *s, wchar_t *pwcs, size_t n);
size_t				ft_wcslen(const wchar_t *s);
int					conv_to_utf8(int wbytes, wchar_t wchar, char *s);

/* ft_xtoa_base.c */
char				*ft_strrev(char *str);
char				*ft_utoa_base(unsigned long long int n, int base);
char				*ft_stoa_base(long long int n, int base);

/* conv_c.c */
int					conv_c(t_buf *buf, t_format *fmt, va_list vl);

/* conv_d.c */
int					conv_d(t_buf *buf, t_format *fmt, va_list vl);

/* conv_prc.c */
int					conv_prc(t_buf *buf, t_format *fmt, va_list vl);

/* conv_s.c */
int					conv_s(t_buf *buf, t_format *fmt, va_list vl);

/* conv_uo.c */
int					conv_u(t_buf *buf, t_format *fmt, va_list vl);
int					conv_o(t_buf *buf, t_format *fmt, va_list vl);

/* conv_wc.c */
int					conv_wc(t_buf *buf, t_format *fmt, va_list vl);

/* conv_wcs.c */
int					conv_wcs(t_buf *buf, t_format *fmt, va_list vl);

/* conv_x.c */
char				*ft_strtoupper(char *arg);
int					conv_x(t_buf *buf, t_format *fmt, va_list vl);
int					conv_p(t_buf *buf, t_format *fmt, va_list vl);

/* utils.c */
void				exit_printf(int code);
int					cleanup_buf(t_buf *pb);
#endif
