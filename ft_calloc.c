/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 14:37:07 by rarruda       #+#    #+#                 */
/*   Updated: 2021/01/21 13:03:50 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t sizeb)
{
	int	*ptr;

	ptr = malloc(nb * sizeb);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nb * sizeb);
	return (ptr);
}
