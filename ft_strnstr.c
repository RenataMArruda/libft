/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 11:14:10 by rarruda       #+#    #+#                 */
/*   Updated: 2021/01/15 12:46:00 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp_little(const char *big, const char *little, \
		size_t len_little, size_t i)
{
	size_t	j;

	j = 0;
	while (j < len_little)
	{
		if (big[i] != little[j])
		{
			return (big[i] - little[j]);
		}
		i++;
		j++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len_little;
	size_t	len_big;
	size_t	i;
	size_t	j;

	len_little = ft_const_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	if (n == 0 || n < len_little)
		return (NULL);
	len_big = ft_const_strlen(big);
	i = 0;
	while (i <= (n - len_little) && i <= (len_big - len_little))
	{
		if (big[i] == little[0])
		{
			j = cmp_little(big, little, len_little, i);
			if (j == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
