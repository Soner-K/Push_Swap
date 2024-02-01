/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:59:28 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 14:50:33 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Finds and returns a string that is between two given separators.
 * @param s The string to iterate through.
 * @param c The separator.
 * @param pos A pointer containing the previous position
 * of the given separator in s.
 * @returns The substring between two separators.
 * NULL if the allocation failed.
 */
static char	*ft_cut(char const *s, char c, size_t *pos)
{
	size_t	i;
	size_t	first_pos;
	char	*str;

	i = 0;
	while (s[*pos] == c && s[*pos])
		(*pos)++;
	first_pos = *pos;
	while (s[*pos] != c && s[*pos])
		(*pos)++;
	str = (char *)malloc((*pos - first_pos + 1) * sizeof(char));
	if (!str)
		return (str);
	while (first_pos + i < *pos)
	{
		str[i] = s[first_pos + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief Counts the words in a string, with a given char
 * acting as a separator.
 * @param s The string for which to count the words.
 * @param c The separator.
 * @returns The number of words.
 */
static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0])
		count++;
	while (s[i])
	{
		if (s[i + 1] && s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

/**
 * @brief Free an array of strings, of a given size.
 * @param tab A pointer to the first string of the array.
 * @param size The number of pointers allocated in the array.
 * @returns void.
 */
static void	delete(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (size--)
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

/**
 * @brief Splits a string into an array of strings, with a char acting
 * as a separator.
 * @param s The string to split.
 * @param c The separator.
 * @returns The array of strings. NULL if any allocation failed.
 */
char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	pos;
	size_t	i;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	tab = ft_calloc(words + 1, sizeof(char *));
	pos = 0;
	i = 0;
	if (!tab)
		return (NULL);
	while (i < words)
	{
		tab[i] = ft_cut(s, c, &pos);
		if (!tab[i])
		{
			delete(tab, words);
			return (NULL);
		}
		i++;
	}
	tab[words] = NULL;
	return (free((char *) s), tab);
}
