/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 15:11:32 by rarruda       #+#    #+#                 */
/*   Updated: 2020/12/02 16:04:13 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_str(char const *s1, char const *s2, char *s3)
{
	int		i;
	int		j;
	int		len1;
	int		len2;

	len1 = ft_const_strlen(s1);
	len2 = ft_const_strlen(s2);
	i = 0;
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		len1;
	int		len2;

	len1 = ft_const_strlen(s1);
	len2 = ft_const_strlen(s2);
	s3 = malloc((len1 + len2 + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	s3 = join_str(s1, s2, s3);
	return (s3);
}
