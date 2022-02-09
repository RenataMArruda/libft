/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 12:11:01 by rarruda       #+#    #+#                 */
/*   Updated: 2020/12/02 15:23:13 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	int		len;

	if (src == NULL)
		return (0);
	len = 0;
	while (((unsigned char *)src)[len] != '\0')
		len++;
	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
		((unsigned char *)dest)[i] = '\0';
	}
	return (len);
}
