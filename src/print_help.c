/*
** EPITECH PROJECT, 2018
** print_help.c
** File description:
** Print help for -h option
*/

#include "lib_prototypes.h"

void print_help(void)
{
	my_putstr("USAGE\n");
	my_putstr("\t./navy [first_player_pid] navy_positions\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("\tfirst_player_pid:  ");
	my_putstr("only for the 3nd player.  pid of the first player\n");
	my_putstr("\tnavy_positions:  ");
	my_putstr("file representing the position of the ships\n");
}
