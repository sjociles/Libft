/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:43:42 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/09 18:13:18 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nb)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*nb && (*nb == ' ' || *nb == '\n' || *nb == '\t' || \
				*nb == '\v' || *nb == '\f' || *nb == '\r'))
		++nb;
	if (*nb == '-')
		negative = -1;
	if (*nb == '-' || *nb == '+')
		++nb;
	while (*nb && *nb >= '0' && *nb <= '9')
	{
		res = res * 10 + (*nb - 48);
		++nb;
	}
	return (res * negative);
}
