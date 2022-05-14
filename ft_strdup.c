/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:47:31 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/13 15:42:05 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s1);
	ptr = malloc(sizeof(*s1) * (len + 1));
	if (ptr == 0)
		return (0);
	ft_memcpy(ptr, s1, len + 1);
	return (ptr);
}
