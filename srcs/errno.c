#include "../includes/cub3d.h"

/**
 * @brief Writes an error message to STDERR.
 * You can add an additional message, otherwise add "" as 2nd argument.
 * @param nbr Signifies with error message from the array to be used.
 * @param msg additional message after the error message.
 */
void	errno(int8_t nbr, char *msg, t_data *data)
{
	static const char	*errors[] = {
		"Too many arguments",
		"Failed reading the file",
		"Wrong colour channel given in input file. Ex: C 220,100,0"
		"You need to give a .cub file as argument",
		"Contains invalid characters",
		"Wrong file extension",
		"The map must be closed/surrounded by walls",
		"Map content needs to come last in the file",
		"Invalid texture",
		"Element typed wrong:",
		"Wrong colour range:",
		"Incomplete file"
	};

	ft_printf_fd(STDERR_FILENO, "Error\n%s%s\n", errors[nbr], msg);
	free_data(data);
	exit(nbr);
}
