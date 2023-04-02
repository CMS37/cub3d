/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:45:22 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/28 19:45:22 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list {
	int				fd;
	int				size;
	int				len;
	char			*line;
	struct s_list	*next;	
}	t_list;

char	*get_next_line(int fd);
char	*ft_find_line(int fd, t_list *line);
char	*ft_make_line(char *backup);
char	*ft_left_line(char *backup);
char	*ft_strchr(char	*str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	**ft_split(char *s, char c);

#endif