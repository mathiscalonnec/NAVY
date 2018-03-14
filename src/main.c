/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Entry point of the program
*/

#include <stdlib.h>
#include "prototypes.h"
#include "lib_prototypes.h"

int main(int ac, char **av)
{
	player_t *player;
	int ret = 0;

	if (ac < 2 || ac > 3)
		return (84);
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
		print_help();
	else {
		player = init_player(ac, av);
		if (player == NULL)
			return (84);
		draw_both_map(player);
		ret = game(player);
		free_player(player);
	}

	return (ret);
}
