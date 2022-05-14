/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:55 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/12 18:07:41 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	p = malloc(count * size);
	i = 0;
	if (p == 0)
		return (0);
	while (i < (count * size))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
