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

# ifndef MB_LEN_MAX
#  define MB_LEN_MAX 4
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
typedef int			(*t_fc)(t_format*, va_list);


