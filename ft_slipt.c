/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slipt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:12:44 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/04 16:57:55 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_split(char **a, int i)
{
	if (!a)
	{
		while (--i >= 0)
			free (a[i]);
		free (a);
	}
}

static int	ft_count_words(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static char	*ft_word(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_n(const char *s, char c, int n)
{
	char	**a;
	int		i;

	if (!s)
		return (NULL);
	a = malloc(sizeof(char *) * (n + 1));
	if (!a)
		return (NULL);
	i = 0;
	while (*s && i < n)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			a[i] = ft_word(s, c);
			ft_free_split(a, i);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	a[i] = NULL;
	return (a);
}

char	**ft_split(char *s, char c)
{
	char	**a;
	int		i;

	if (!s)
		return (NULL);
	a = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!a)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			a[i] = ft_word(s, c);
			ft_free_split(a, i);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	a[i] = NULL;
	return (a);
}
