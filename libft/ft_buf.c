# include "libft.h"

t_buf	*ft_buf_init(t_buf *b, size_t size)
{
	size_t	s;

	s = (size == 0) ? 1024 : size; //make macro for size?
	b->bmax = s;
	b->blen = 0;
	b->buf = malloc(sizeof(char) * s);
	if (b->buf == NULL)
		return (NULL);
	return (b);
}

t_buf	*ft_buf_add(t_buf *b, char *s, size_t len)
{
	if (b->blen + len >= b->bmax)
		if (ft_buf_resize(b, len) == NULL)
			return (NULL);
	ft_memcpy(b->buf + b->blen, s, len);
	b->blen += len;
	b->buf[b->blen] = 0;
	return (b);
}

t_buf	*ft_buffer_resize(t_buf *b, size_t len)
{
	char	*newstr;
	size_t	newsize;

	newsize = sizeof(char) * b->bmax * 2;
	while (b->blen + len >= newsize)
		newsize *= 2;
	newstr = ft_realloc(b->buf, newsize, b->bmax);
	if (newstr == NULL)
		return (NULL);
	b->bmax = newsize;
	b->buf = newstr;
	return (b);
}

t_buf	*ft_buf_set(t_buf *b, int c, size_t len)
{
	if (b->blen + len >= b->bmax)
		if (ft_buf_resize(b, len) == NULL)
			return (NULL);
	ft_memset(b->buf + b->blen, c, len);
	b->blen += len;
	b->buf[b->blen] = 0;
	return (b);
}
