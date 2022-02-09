/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 11:57:26 by rarruda       #+#    #+#                 */
/*   Updated: 2020/12/09 12:04:15 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	j;

	len_src = ft_const_strlen(src);
	len_dest = ft_const_strlen(dest);
	if (dstsize == 0)
		return (len_src);
	i = 0;
	j = len_dest;
	if ((dstsize - 1) < len_dest)
		return (dstsize + len_src);
	else
	{
		while (((unsigned char *)src)[i] != '\0' && j < (dstsize - 1))
		{
			((unsigned char *)dest)[j] = ((unsigned char *)src)[i];
			j++;
			i++;
		}
		((unsigned char *)dest)[j] = '\0';
	}
	return (len_dest + len_src);
}
