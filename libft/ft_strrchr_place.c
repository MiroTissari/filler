
int	ft_strrchr_place(const char *s, int c)
{
	int		x;
	int		y;

	x = 0;
	y = -1;
	while (s[x] != '\0')
	{
		if (((unsigned char *)s)[x] == c)
			y = x;
		x++;
	}
	if (s[x] == '\0' && s[x] == c)
		return (x);
	else if (s[x] == '\0' && y != -1)
		return (y);
	return (0);
}
