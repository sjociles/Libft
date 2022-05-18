/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:46:09 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/18 15:38:58 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *neew)
{
	t_list	*tmp;

	if (lst && neew)
	{
		if (*lst == NULL)
			*lst = neew;
		else
		{
			tmp = ft_lstlast(*lst);
			tmp->next = neew;
		}
	}
}
