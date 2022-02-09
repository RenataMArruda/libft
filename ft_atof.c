/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 17:45:48 by rarruda       #+#    #+#                 */
/*   Updated: 2022/02/09 17:45:52 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_if_number(char *str)
{
	size_t	len;
	size_t	i;
	int		position;

	i = 0;
	position = -1;
	len = ft_strlen(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] == '.' || ft_isdigit(str[i]) == 1))
	{
		if (str[i] == '.')
		{
			if (position != -1)
				return (-2);
			else
				position = i;
		}
		i++;
	}
	if (i != len)
		return (-2);
	return (position);
}

float	ft_atof(char *str)
{
	float	value;
	int		position;
	size_t	len;
	char	*str2;

	len = ft_strlen(str);
	position = check_if_number(str);
	if (position == -2)
		return (0);
	if (position == -1)
		value = ft_atoi(str);
	else
	{
		str2 = malloc((len + 1) * sizeof(char));
		if (str2 == NULL)
			return (0);
		ft_strlcpy(str2, str, position + 1);
		ft_strlcat(str2, str + position + 1, len + 1);
		value = ft_atoi(str2);
		value = value / ft_power(len - position - 1);
		free(str2);
		str2 = NULL;
	}
	return (value);
}
