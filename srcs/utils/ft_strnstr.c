#include "pipex.h"

char	*ft_strnstr(const char *str, char *tofind)
{
	size_t	s;
	size_t	t;

	s = 0;
	t = 0;
	if (tofind [0] == '\0')
		return ((char *)str);
	while (str[s] != '\0')
	{
		while (str [s + t] == tofind[t])
		{
			if (tofind[t + 1] == '\0')
				return ((char *)str + s);
			t++;
		}
		t = 0;
		s++;
	}
	return (0);
}