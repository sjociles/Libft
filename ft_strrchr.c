/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:59:55 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/12 15:50:15 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			len;
	int			i;
	const char	*p;

	len = ft_strlen(s);
	p = s + len;
	if (!s)
		return (0);
	i = len;
	while (i >= 0)
	{
		if (*p == ((char)c))
			return ((char *)p);
		p--;
		i--;
	}
	return (0);
}
