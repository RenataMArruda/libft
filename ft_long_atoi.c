/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 12:11:43 by rarruda       #+#    #+#                 */
/*   Updated: 2021/10/22 13:11:45 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test_negative(const char *str, int i)
{
	int	negative;

	negative = 0;
	if (str[i] == '-')
		negative = -1;
	else if (str[i] == '+')
		negative = 1;
	return (negative);
}

static unsigned long long	power(unsigned long long p)
{
	unsigned long long	a;
	unsigned long long	b;

	a = 0;
	b = 1;
	while (a < p)
	{
		b = b * 10;
		a++;
	}
	return (b);
}

static int	longer(int negative)
{
	if (negative == 1)
		return (-1);
	if (negative == -1)
		return (0);
	return (0);
}

static unsigned long long	beginning(const char *str)
{
	unsigned long long	i;

	i = 0;
	while ((str[i] != '\0') && (str[i] == 32 || str[i] == '\f' || \
		str[i] == '\n' || str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	return (i);
}

long	ft_long_atoi(const char *str)
{
	unsigned long long	i;
	unsigned long long	j;
	int					negative;
	unsigned long long	value;

	i = beginning(str);
	negative = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		negative = test_negative(str, i);
		i++;
	}
	j = i;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
		i++;
	value = 0;
	while (j < i)
	{
		value = value + (str[j] - 48) * power((i - j) - 1);
		j++;
	}
	if (value > 9223372036854775807)
		return (longer(negative));
	return (value * negative);
}
