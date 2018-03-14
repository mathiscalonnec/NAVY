/*
** EPITECH PROJECT, 2018
** init_player.c
** File description:
** initialisation of the struct player
*/

#include <stdlib.h>
#include "player.h"
#include "lib_prototypes.h"
#include "prototypes.h"
#include "global.h"

global_t global;

player_t *init_player(int ac, char **av)
{
	player_t *player = malloc(sizeof(player_t) * 1);

	if (ac == 3) {
		global.pid = my_getnbr(av[1]);
		player->player_map = create_map(av[2]);
		player->turn = 0;
	}
	else {
		player->player_map = create_map(av[1]);
		player->turn = 1;
	}
	player->enemy_map = fill_map_with_dots();
	if (player->player_map == NULL) {
		free(player);
		return (NULL);
	}
	if (ac == 3)
		connection(0, global.pid);
	else
		connection(1, 0);
	return (player);
}

void free_player(player_t *player)
{
	free(player->player_map);
	free(player->enemy_map);
	free(player);
}
