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

int	count_words(const char *str, char c)
{
	int	counter;
	int	trigger;

	counter = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			counter++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (counter);
}

char	*word_up(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (0);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

size_t  ft_strlensplit(char **s)
{
	size_t  i;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_splitfree(char **s)
{
	size_t	i;

	i = 0;
	if (!s && !*s)
		return ;
	while (i < ft_strlensplit(s))
		free((void *)s[i++]);
	free(s);
	*s = NULL;
}

char	**ft_process(char const *s, char c, char **split)
{
	size_t  i;    
    size_t  j;
    int     index;

	i = 0;
    j = 0;
    index = -1; 
    while (i <= ft_strlen(s))
    {   
        if (s[i] != c && index < 0)
            index = i;
        else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
        {
            split[j++] = word_up(s, index, i);
            index = -1;
        }
        i++;                                                                                                              
    }
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
//	size_t	i;
//	size_t	j;
//	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	if (ft_process(s, c, split) != 0)
		return (split);
	else if (ft_process(s, c, split) == 0)
	{
		ft_splitfree((char **)split);
		return (0);
	}
}
//	i = 0;
//	j = 0;
//	index = -1;
//	while (i <= ft_strlen(s))
//	{
//		if (s[i] != c && index < 0)
//			index = i;
//		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
//		{
//			split[j++] = word_up(s, index, i);
//			index = -1;
//		}
//		i++;
//	}
//	split[j] = 0;
//	ft_splitfree((char **)s);
//	return (split);
//}
