#include "../includes/cub3d.h"

// /**
//  * @brief Writes an error message to STDERR.
//  * You can add an additional message, otherwise add "" as 2nd argument.
//  * @param nbr Signifies with error message from the array to be used.
//  * @param msg additional message after the error message.
//  */
// void	errno(int8_t nbr, char *msg)
// {
// 	static const char	*errors[] = {
// 		"Contains invalid characters",
// 		"Wrong file extension",
// 		"The map must be closed/surrounded by walls",
// 		"Map content cannot be seperated by spaces",
// 		"Map content needs to come last in the file",
// 		"Invalid texture",
// 		"Element typed wrong:",
// 		"Wrong colour range:",
// 		"Incomplete file"
// 	};

// 	ft_printf_fd(STDERR_FILENO, "Error\n%s%s\n", errors[nbr], msg);
// }
