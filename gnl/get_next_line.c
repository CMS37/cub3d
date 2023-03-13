/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:44:41 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/28 19:44:41 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_list(t_list **start, int fd)
{
	t_list	*node;

	if (fd < 0)
		return (NULL);
	node = *start;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->line = (char *)malloc(sizeof(char));
	if (!node->line)
		return (NULL);
	node->line[0] = '\0';
	node->size = 1;
	node->len = 0;
	node->next = *start;
	*start = node;
	return (node);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len2;

	if (!s)
		return (NULL);
	len2 = ft_strlen(s);
	if (len2 < start)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

char	*ft_find_line(int fd, t_list *line)
{
	char	*buf;
	char	*line2;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(line->line) && line->size != 0)
	{
		line->size = read(fd, buf, BUFFER_SIZE);
		if (line->size == -1)
		{
			free(buf);
			free(line->line);
			free(line);
			return (NULL);
		}
		buf[line->size] = '\0';
		line2 = ft_strdup(line->line);
		free(line->line);
		line->line = ft_strjoin(line2, buf);
		free(line2);
	}
	free (buf);
	return (line->line);
}

void	lastcall(t_list **head)
{
	t_list	*next;

	while ((*head)->size == 0 && !(*head)->line[0])
	{
		next = *head;
		*head = (*head)->next;
		free(next->line);
		free(next);
		if (!(*head))
			break ;
	}
}

char	*get_next_line(int fd)
{
	t_list			*line;
	static t_list	*head;
	char			*tmp;
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_list(&head, fd);
	line->line = ft_find_line(fd, line);
	if (!line->line ||!line->line[0])
	{
		lastcall(&head);
		return (NULL);
	}
	tmp = ft_strdup(line->line);
	free(line->line);
	line->len = 0;
	while (tmp[line->len] && tmp[line->len] != '\n')
		line->len++;
	if (tmp[line->len] == '\n')
		line->len++;
	new_line = ft_substr(tmp, 0, line->len);
	line->line = ft_substr(tmp, line->len, ft_strlen(tmp));
	free(tmp);
	return (new_line);
}
