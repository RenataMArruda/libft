/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 19:28:03 by rarruda       #+#    #+#                 */
/*   Updated: 2020/11/25 16:58:22 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	size_t	i;
	size_t	j;
	char	*subs;

	n = ft_const_strlen(s);
	if ((n - start) > len)
		subs = malloc(len * sizeof(char));
	else
		subs = malloc((n - start) * sizeof(char));
	if (subs == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < n && i < (start + len))
	{
		subs[j] = s[i];
		i++;
		j++;
	}
	subs[j] = '\0';
	return (subs);
}
