/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:14:38 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 01:14:40 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	extension_check(t_data *data, char *map_name, char *ext)
{
	size_t	len;

	len = ft_strlen(map_name);
	while (len > 0)
	{
		if (map_name[len] == '.')
			break ;
		len--;
	}
	if (ft_strcmp(&map_name[len], ext) != 0)
		return (errno(INV_EXT, "", data));
}

void	error_check(t_data *data, int32_t argc, char **argv)
{
	int32_t	fd;
	char	*file;

	if (argc > 2)
		errno(ARGS, "", data);
	if (argc <= 1)
		errno(NO_CUB, "", data);
	extension_check(data, argv[1], ".cub");
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		errno(READ_FAIL, "", data);
	file = read_file(fd);
	element_check(data, &file);
	extract_map(data, file);
}
