#include "asm.h"

int		ft_check_extention(char *file)
{
	if (ft_strstr(file, ".s") && !ft_strncmp(file + ft_strlen(file) - 2, ".s",
		2))
		return (1);
	return (0);
}

int		ft_check_types(char **args, t_op *op)
{
	int i;

	i = 0;
	while (args && args[i] && i < op->n_par)
		if ((op->type_arg[i] & args[i][0]) == op->type_arg[i])
			return (0);
		else
			i++;
	return (1);
}

int		ft_check_num(char *str)
{
	int j;

	j = -1;
	while (++j < (int)ft_strlen(str))
		if (!ft_isdigit(str[j]) && !((str[j] == '-'
			|| str[j] == '+') && !j))
			return (0);
	return (1);
}