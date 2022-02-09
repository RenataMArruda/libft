/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 15:06:40 by rarruda       #+#    #+#                 */
/*   Updated: 2020/11/25 15:59:01 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_beg(char const *s1, char const *set, int lens1)
{
	int		i;
	int		j;
	int		k;
	int		lenset;

	lenset = ft_const_strlen(set);
	i = 0;
	j = 0;
	k = -1;
	while (i < lens1)
	{
		while (j < lenset)
		{
			if (s1[i] != set[j])
				j++;
			else
			{
				i++;
				k = i;
				j = 0;
			}
		}
		i++;
	}
	return (k);
}

static int	find_end(char const *s1, char const *set, int lens1)
{
	int		i;
	int		j;
	int		k;
	int		lenset;

	lenset = ft_const_strlen(set);
	i = lens1 - 1;
	j = 0;
	k = -1;
	while (i >= 0)
	{
		while (j < lenset)
		{
			if (s1[i] != set[j])
				j++;
			else
			{
				i--;
				k = i;
				j = 0;
			}
		}
		i--;
	}
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ts1;
	int		lens1;
	int		i;
	int		j;
	int		k;

	lens1 = ft_const_strlen(s1);
	i = find_beg(s1, set, lens1);
	j = find_end(s1, set, lens1);
	if (i == -1)
		i = 0;
	if (j == -1)
		j = lens1 - 1;
	ts1 = malloc((j - i + 2) * sizeof(char));
	if (ts1 == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		ts1[k] = s1[i];
		k++;
		i++;
	}
	ts1[k] = '\0';
	return (ts1);
}
