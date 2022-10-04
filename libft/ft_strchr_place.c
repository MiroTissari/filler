

int	ft_strchr_place(const char *s, int c)
{
	int		x;
	char	cc;

	cc = c;
	x = 0;
	if (!s)
		return (0);
	while (s[x] != '\0')
	{
		if (s[x] == cc)
			return (x);
		x++;
	}
	if (s[x] == '\0' && s[x] == cc)
		return (x);
	return (0);
}
