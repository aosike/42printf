void	exit_printf(int code)
{
	write(2, "malloc error\n", 13);
	exit(code);
}

int	cleanup_buf(t_buf *pb)
{
	FT_BUFFER_FREE(pb);
	return (-1);
}