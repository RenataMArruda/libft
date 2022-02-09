/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_const_strlen.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 16:36:00 by rarruda       #+#    #+#                 */
/*   Updated: 2022/02/09 16:36:03 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_const_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
