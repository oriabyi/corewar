#include "asm.h"

void	ft_add_label(t_asm *glob, char **arr)
{
	if (glob->n_labels == -1)
		glob->labels = (t_label **)malloc(sizeof(t_label *));
	else
	{
		glob->labels = (t_label **)realloc(glob->labels, sizeof(t_label *)
		* (glob->n_labels + 2));
	}
	glob->n_labels++;
	glob->labels[glob->n_labels] = (t_label *)malloc(sizeof(t_label));
	glob->labels[glob->n_labels]->name = ft_strdup(arr[0]);
	glob->labels[glob->n_labels]->name[ft_strlen(glob->labels[glob->n_labels]->name) - 1] = '\0';
	glob->labels[glob->n_labels]->indx = glob->cur;
}

void	ft_add_mislabel(t_asm *glob, char *label, t_op *op)
{
	int i;

	i = (op->label_size) ? 2 : 4;
	if (glob->n_mislabels == -1)
		glob->mislabels = (t_mislabel **)malloc(sizeof(t_mislabel *));
	else
	{
		glob->mislabels = (t_mislabel **)realloc(glob->mislabels,
												 sizeof(t_mislabel *) * (glob->n_mislabels + 2));
	}
	glob->n_mislabels++;
	glob->mislabels[glob->n_mislabels] = (t_mislabel *)malloc(sizeof(t_mislabel));
	glob->mislabels[glob->n_mislabels]->name = ft_strdup(label);
	glob->mislabels[glob->n_mislabels]->size = op->label_size;
	glob->mislabels[glob->n_mislabels]->cur = glob->cur;
	glob->mislabels[glob->n_mislabels]->start_op = glob->start_op;
	while (i--)
		glob->commands[++(glob->cur)] = 0;
}

void	ft_add_data(t_asm *glob, char *arg, t_op *op)
{
	if (arg[0] == 'r')
		glob->commands[++(glob->cur)] = (char)ft_atoi(arg + 1);
	else if (arg[0] == DIRECT_CHAR && arg[1] != LABEL_CHAR)
	{
		if (!op->label_size)
			ft_get_four_bits(glob, arg);
		else
			ft_get_two_bits(glob, arg);
	}
	else if (arg[0] == DIRECT_CHAR)
	{
		ft_add_mislabel(glob, arg + 2, op);
		return ;
	}
	(ft_check_num(arg + 1)) ? 0 : ft_put_error(13, arg);
}

void	ft_add_prosses(char **arr, t_asm *glob, int i, t_op *op)
{
	char	**prosses;
	char 	*separators;
	char	*arg;
	int		j;

	separators = ft_strdup(" \t.\v\f\r");
	separators[2] = SEPARATOR_CHAR;
	arg = ft_joinarg(&(arr[++i]));
	prosses = ft_strsplit_spec(arg, separators, COMMENT_CHAR);
	glob->start_op = glob->cur;
	glob->commands[glob->cur] = (char)op->id;
	if (op->octal)
		glob->commands[++(glob->cur)] = ft_get_type_n(prosses, op);
	j = 0;
	if (!ft_check_types(prosses, op))
		ft_put_error(11, arg);
	while (prosses && prosses[j] && j < op->n_par)
		ft_add_data(glob, prosses[j++], op);
	ft_free_line(&separators);
	if (j != op->n_par || (prosses && prosses[j]))
		ft_put_error(8, arr[i - 1]);
	ft_free_line(&arg);
	ft_free_arr(prosses);
}

void	ft_add_op(char *line, t_asm	*glob)
{
	char **arr;

	arr = ft_strsplit_spec(line, " \t\v\f\r", COMMENT_CHAR);
	if (!arr || !arr[0])
		;
	else if (!ft_strcmp(arr[0], NAME_CMD_STRING))
		ft_get_name(glob, arr, line);
	else if (!ft_strcmp(arr[0], COMMENT_CMD_STRING))
		ft_get_comment(glob, arr, line);
	else if (glob->name && glob->comment && ft_strlen(arr[0]))
		ft_get_prosses(glob, arr);
	else
		ft_put_error(14, NULL);
	ft_free_arr(arr);
}