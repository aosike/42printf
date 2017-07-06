#ifndef FT_BUF_H
# define FT_BUF_H

# include "libft.h"

typedef struct	s_buf
{
	char		*buf;
	size_t		blen;
	size_t		bmax;
}				t_buf;
