/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 15:16:33 by rarruda       #+#    #+#                 */
/*   Updated: 2021/02/17 12:18:57 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate_memory(int cpy, int k)
{
	char	*str;
	int		count;

	count = 1;
	while (cpy >= 10)
	{
		cpy /= 10;
		count++;
	}
	if (k == 1)
	{
		str = malloc((count + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
	}
	else
	{
		str = malloc((count + 2) * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '-';
	}
	return (str);
}

static void	make_str(char *str, int k, int n, int cpy)
{
	int		i;
	int		count;
	int		temp;

	temp = cpy;
	count = 1;
	while (temp >= 10)
	{
		temp /= 10;
		count++;
	}
	i = 0;
	while (i < count)
	{
		n = cpy % ft_power(count - 1 - i);
		cpy = cpy / ft_power(count - 1 - i);
		str[k] = cpy + 48;
		cpy = n;
		i++;
		k++;
	}
	str[k] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		cpy;
	int		k;

	if (n == -2147483648)
	{
		str = malloc(12 * sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	k = 1;
	if (n < 0)
		k = -1;
	cpy = n * k;
	str = allocate_memory(cpy, k);
	if (k == 1)
		k = 0;
	else if (k == -1)
		k = 1;
	make_str(str, k, n, cpy);
	return (str);
}
