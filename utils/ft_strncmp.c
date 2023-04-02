/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:44:51 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/02 19:43:00 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (s11[i] && i < n)
	{
		if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
		i++;
	}
	if (s22[i] == '\0' || i == n)
		return (0);
	else
		return (-s22[i]);
}
