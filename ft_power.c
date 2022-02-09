/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_power.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 15:17:21 by rarruda       #+#    #+#                 */
/*   Updated: 2022/02/09 15:17:26 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int p)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a < p)
	{
		b = b * 10;
		a++;
	}
	return (b);
}