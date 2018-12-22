#include "libft.h"

char	**ft_arrjoin_del(char **arr1, char **arr2)
{
	char **arr;

	arr = ft_arrjoin(arr1, arr2);
	ft_free_arr(arr1);
	ft_free_arr(arr2);
	return (arr);
}