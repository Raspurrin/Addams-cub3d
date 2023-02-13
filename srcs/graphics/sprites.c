#include "../../includes/cub3d.h"

/**
 * @brief Checking if the sprites are in the Field of View
 * So the radius of the player FOV and whether a wall is blocking the view or not.
 */
bool	FOV_check(t_data *data, t_wall wall, t_sprite *sprite)
{
	int32_t	column;

	column = 0;
	sprite->distance = data->player.pos
	if (sprite->distance < wall.distance && /*inside FOV radius??*/)
	{
		// calculate from which column to start drawing
		column = // aaaaaaaaaaa
	}
	return (column);
}

/**
 * @brief Ordering the sprites by distance in a linked list, so I know which has to be drawn first.
 */
void	ordering_sprites()
{

}

/**
 * @brief Every frame of the main loop I will update the textures in the linked list with
 * the next texture frame in their individual arrays.
 */
void	animation()
{

}

/**
 * @brief After drawing the walls, I draw the sprites if they are in FOV.
 */
void	drawing_sprites(t_data *data)
{
	ordering_sprites();
	t_sprite *sprites;

	sprites = data->sprites;
	while (sprites != NULL)
	{
		if (FOV_check(data->wall, data->sprites))
		{
			
		}
		sprites = sprites->next;
	}
}
