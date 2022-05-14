/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:28:22 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/12 16:25:40 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	hay = (char *)haystack;
	if (needle[0] == '\0')
		return (hay);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (j + i) < len)
		{
			if (haystack[i + j] == '\0' && needle[j] == '\0')
				return (hay + i);
			j++;
		}
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
