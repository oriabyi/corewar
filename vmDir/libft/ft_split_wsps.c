/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_wsps                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <aleksandr.rabyj@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:32:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/05/02 15:17:56 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_trimfsplit(char const *s, char lt, int *c)
{
	int			j;
	int			q;
	char		*dest;
	int			temp;

	j = 0;
	q = (int)(ft_strlen(s) - 1);
	temp = q;
	if (!(dest = (char*)malloc((sizeof(char)) * (q + 1))))
		return (NULL);
	while ((s[*c] == lt || s[*c] == ' ' || s[*c] == '\t') && s[(*c)++])
		;
	while ((s[q] == lt || s[q] == '\t' || s[q] == ' ') && s[q--])
		;
	while (s[*c] && *c <= q && (s[*c] != lt && s[*c] != ' ' && s[*c] != '\t'))
		dest[j++] = s[(*c)++];
	(*c)++;
	while (j <= temp)
		dest[j++] = '\0';
	return (dest);
}

static int		ft_numbofwords(char const *s, char c)
{
	int			i;
	int			counter;
	int			iw;

	i = -1;
	counter = 1;
	if (!s)
		return (-1);
	iw = (s[0] == c) ? 0 : 1;
	while (s[++i])
	{
		if (s[i] != c && s[i] != ' ' && s[i] != '\t' && iw == 1 && counter++)
			iw = 0;
		if (s[i] == c || s[i] == ' ' || s[i] == '\t')
			iw = 1;
	}
	return (counter - 1);
}

char			**ft_split_wsps(const char *str, char c)
{
	int			j;
	int			wrd;
	int			counter;
	char		**s;

	if (!str || ft_iswsps(str) || (counter = 0))
		return (NULL);
	j = -1;
	wrd = ft_numbofwords(str, c);
	if (!(s = (char **)malloc(sizeof(char *) * (wrd + 2))))
		return (NULL);
	while (++j < wrd && str[counter])
	{
		s[j] = ft_trimfsplit(str, c, &counter);
		if (!s[j])
		{
			while (j > -1)
				ft_strdel(&s[j--]);
			return (NULL);
		}
	}
	s[j] = NULL;
	return (s);
}
