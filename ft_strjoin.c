/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:54:02 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/12 19:19:31 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len1;
	int		len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!s1 || !s2 || str == 0)
		return (0);
	while (len1--)
	{
		str[i] = s1[i];
		i++;
	}
	len1 = i;
	i = 0;
	while (len2--)
		str[len1++] = s2[i++];
	str[len1] = '\0';
	return (str);
}
