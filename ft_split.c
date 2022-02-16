/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 16:08:03 by rarruda       #+#    #+#                 */
/*   Updated: 2021/01/29 19:16:58 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	id_c(char const *s, int len, char c)
{
	int		cs;
	int		i;

	i = 0;
	cs = 0;
	while (i < len)
	{
		if (s[i] == c)
		{
			cs++;
			i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
		i++;
	}
	if (s[0] == c)
		cs--;
	if (s[len - 1] == c)
		cs--;
	return (cs);
}

static char	**malloc_and_free_splitted(char **splitted, int a, int i, int j)
{
	if (i != j)
	{
		splitted[a] = malloc((i - j + 1) * sizeof(char));
		if (splitted[a] == NULL)
		{
			while (a >= 0)
			{
				free(splitted[a]);
				a--;
			}
			free(splitted);
			return (NULL);
		}
		splitted[a][i - j] = '\0';
	}
	return (splitted);
}

static char	**make_split(char **splitted, char const *s, char c, int i)
{
	int		j;
	int		a;
	int		b;

	a = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		splitted = malloc_and_free_splitted(splitted, a, i, j);
		if (splitted == NULL)
			return (NULL);
		b = 0;
		while ((j + b) < i)
		{
			splitted[a][b] = s[j + b];
			b++;
		}
		a++;
	}
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		len;
	int		cs;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_const_strlen(s);
	if (len == 0)
		cs = -1;
	else
		cs = id_c(s, len, c);
	splitted = malloc((cs + 2) * sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	splitted = make_split(splitted, s, c, i);
	if (splitted == NULL)
		return (NULL);
	splitted[cs + 1] = NULL;
	return (splitted);
}
