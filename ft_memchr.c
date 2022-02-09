/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 12:26:14 by rarruda       #+#    #+#                 */
/*   Updated: 2020/11/11 12:27:05 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (NULL);
	}
	while (i < n)
	{
		if (((unsigned char *)str)[i] == ((unsigned char)c))
		{
			return ((void *)str + i);
		}
		i++;
	}
	return (NULL);
}
