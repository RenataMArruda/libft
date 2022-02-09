/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 11:45:22 by rarruda       #+#    #+#                 */
/*   Updated: 2020/11/11 11:47:20 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	n;

	n = ft_const_strlen(str);
	while (n >= 0)
	{
		if (str[n] == c)
			return ((char *)str + n);
		n--;
	}
	return (NULL);
}
