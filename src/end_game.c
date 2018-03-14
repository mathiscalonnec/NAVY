/*
** EPITECH PROJECT, 2018
** end_game.c
** File description:
** end game
*/

#include "prototypes.h"
#include "player.h"
#include "macros.h"
#include "global.h"

extern global_t global;

int end_game(player_t *player)
{
	int i = 0;
	int b = 0;

	while (player->player_map[i] != '\0') {
		if (IS_NUM(player->player_map[i]) == 1)
			b = 1;
		i++;
	}
	if (global.cross != 14 && b == 1)
		return (1);
	return (0);
}
