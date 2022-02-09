/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 15:26:39 by rarruda       #+#    #+#                 */
/*   Updated: 2020/12/02 15:27:19 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	negative(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0 && n != -2147483648)
	{
		n = n * (-1);
		ft_putchar_fd('-', fd);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	cpy;
	int	count;
	int	i;

	n = negative(n, fd);
	cpy = n;
	if (n != -2147483648)
	{
		count = 1;
		while (cpy >= 10)
		{
			cpy /= 10;
			count++;
		}
		cpy = n;
		i = 0;
		while (i < count)
		{
			n = cpy % ft_power(count - 1 - i);
			cpy = cpy / ft_power(count - 1 - i);
			ft_putchar_fd((cpy + 48), fd);
			cpy = n;
			i++;
		}
	}
}
