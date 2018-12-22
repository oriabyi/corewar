#include "libft.h"

char	*ft_strjoin_del(char *s1, char *s2)
{
	char *str;

	str = ft_strjoin(s1, s2);
	ft_free_line(&s1);
	ft_free_line(&s2);
	return (str);
}