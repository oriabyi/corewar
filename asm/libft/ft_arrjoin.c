#include "libft.h"

char	**ft_arrjoin(char **arr1, char **arr2)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = ft_arrsize(arr1);
	j = ft_arrsize(arr2);
	k = i + j;
	arr = (char **)malloc((k + 1)
			* sizeof(char *));
	arr[k] = NULL;
	while (j--)
		arr[--k] = arr2[j];
	while (i--)
		arr[--k] = arr1[i];
	return (arr);
}