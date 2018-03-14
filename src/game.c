/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** main part
*/

#include "prototypes.h"
#include "lib_prototypes.h"
#include "global.h"

extern global_t global;

int game(player_t *player)
{
	point_t point;

	global.cross = 0;
	while (end_game(player) == 1) {
		if (player->turn == 0) {
			my_putstr("\nwaiting for enemy's attack...\n");
			point = receive_value();
			modify_array_receiver(point, player);
			player->turn = 1;
			draw_both_map(player);
		}
		else if (player->turn == 1) {
			point = read_coordinates();
			send_value(point);
			modify_array_sender(point, player);
			player->turn = 0;
		}
	}
	return (end_message(player));
}

int end_message(player_t *player)
{
	if (player->turn == 1) {
		my_putstr("\nEnemy won\n");
		return (1);
	}
	if (player->turn == 0) {
		draw_both_map(player);
		my_putstr("\nI won\n");
		return (0);
	}
	return (-1);
}
