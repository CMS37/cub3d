/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:03:25 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/02 19:39:03 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	arrlen(char *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			cnt++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		cnt++;
	return (cnt);
}

size_t	nextend(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**arr_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	len;
	size_t	len_arr;

	if (!s)
		return (NULL);
	len_arr = arrlen(s, c);
	arr = (char **)malloc(sizeof(char *) * (len_arr + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len_arr)
	{
		while (*s && *s == c)
			s++;
		len = nextend(s, c);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arr[i])
			return (arr_free(arr));
		ft_strlcpy(arr[i++], s, len + 1);
		s += len;
	}
	arr[i] = NULL;
	return (arr);
}
