/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjociles <sjociles@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:24:41 by sjociles          #+#    #+#             */
/*   Updated: 2022/05/19 18:21:18 by sjociles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numstring(char const *s1, char c)
{
	int	num_str;
	int	same;

	num_str = 0;
	same = 0;
	if (!s1)
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			same = 0;
		else if (same == 0)
		{
			same = 1;
			num_str++;
		}
		s1++;
	}
	return (num_str);
}

int	numchar(char const *s2, char c, int i)
{
	int	len;

	len = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_splitfree(char const **split, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)split[j]);
	}
	free(split);
	return (NULL);
}

char	**affect(char const *s, char **split, char c, int total_count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < total_count)
	{
		k = 0;
		while (s[i] == c)
			i++;
		split[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (split[j] == NULL)
			return (ft_splitfree((char const **)split, j));
		while (s[i] != '\0' && s[i] != c)
			split[j][k++] = s[i++];
		split[j][k] = '\0';
		j++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		total_count;

	if (!s)
		return (NULL);
	total_count = numstring(s, c);
	split = (char **)malloc(sizeof(char *) * (total_count + 1));
	if (!split)
		return (NULL);
	return (affect(s, split, c, total_count));
}
