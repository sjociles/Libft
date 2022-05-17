/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:42:13 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/17 21:15:15 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	char	tmp;

	j = ft_strlen(str) - 1;
	i = 0;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int	ft_count(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_convert(int n, char *str, int negative)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		str[len++] = '0' + (n % 10);
		n = (n / 10);
	}
	if (negative)
		str[len] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = (n < 0);
	if (negative)
		n = -n;
	str = ft_calloc((ft_count(n) + 1 + negative), sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	ft_convert(n, str, negative);
	ft_strrev(str);
	return (str);
}
