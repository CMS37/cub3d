/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:19:16 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/26 20:45:55 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*check_xpm_file(char *tmp)
{
	int fd;

	fd = open(tmp, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		printErr("Fail Open Xpm Files");
	}
	close(fd);
	return(ft_strdup(tmp));
}

int hex_to_int(char *hex) {
    int int_value = 0;

    // Iterate over hex string
    for (int i = 0; hex[i] != '\0'; i++) {
        // Convert hex digit to decimal value
        int decimal_value;
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal_value = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal_value = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal_value = hex[i] - 'a' + 10;
        } else {
            // Invalid hex digit
            return 0;
        }

        // Shift and add decimal value to build int value
        int_value = (int_value << 4) | decimal_value;
    }

    return int_value;
}

static int	rgb_to_hex(char **str)
{
	int		red;
	int		green;
	int		blue;
	char	*hex;
    char	hex_digits[] = "0123456789ABCDEF";

	red = atoi(str[0]);
	green = atoi(str[1]);
	blue = atoi(str[2]);
	hex = (char *)malloc(sizeof(char) * 6);
    hex[0] = hex_digits[red >> 4];
    hex[1] = hex_digits[red & 0x0F];
    hex[2] = hex_digits[green >> 4];
    hex[3] = hex_digits[green & 0x0F];
    hex[4] = hex_digits[blue >> 4];
    hex[5] = hex_digits[blue & 0x0F];
    hex[6] = '\0';
	return (hex_to_int(hex));
}

int	is_xpm(char *tmp, t_info *info)
{
	char	**s1 = NULL;

	if (tmp[0] == 'N' && tmp[1] == 'O')
	{
		if (info->img.no != NULL)
			printErr("Check Map identifier");
		info->img.no = check_xpm_file(tmp + 3);
	}
	else if(tmp[0] == 'S' && tmp[1] == 'O')
	{
		if (info->img.so != NULL)
			printErr("Check Map identifier");
		info->img.so = check_xpm_file(tmp + 3);
	}
	else if(tmp[0] == 'W' && tmp[1] == 'E')
	{
		if (info->img.we != NULL)
			printErr("Check Map identifier");
		info->img.we = check_xpm_file(tmp + 3);
	}
	else if(tmp[0] == 'E' && tmp[1] == 'A')
	{
		if (info->img.ea != NULL)
			printErr("Check Map identifier");
		info->img.ea = check_xpm_file(tmp + 3);
	}
	else if(tmp[0] == 'F')
	{
		if (info->img.floor != NULL)
			printErr("Check Map identifier");
		s1 = ft_split(tmp + 2, ',');
		info->f_color = rgb_to_hex(s1);
		printf("f : %d\n", info->f_color);
		free(s1);
	}
	else if(tmp[0] == 'C')
	{
		if (info->img.ceiling != NULL)
			printErr("Check Map identifier");
		s1 = ft_split(tmp + 2, ',');
		info->c_color = rgb_to_hex(s1);
		printf("c : %d\n", info->c_color);
		free(s1);
	}
	else
		return(0);
	return (1);	
}
