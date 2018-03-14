/*
** EPITECH PROJECT, 2018
** modify_array.c
** File description:
** modify array
*/

#include <unistd.h>
#include "global.h"
#include "macros.h"
#include "prototypes.h"
#include "lib_prototypes.h"

extern global_t global;

void modify_array_receiver(point_t point, player_t *player)
{
	int y = point.x;
	int x = point.y;

	if (IS_NUM(get_element_at(player->player_map, x, y)) == 0) {
		set_element_at(player->player_map, x, y, 'o');
		print_result(y, x, ":  missed\n");
		usleep(10000);
		kill(global.pid, SIGUSR1);
	}
	else {
		set_element_at(player->player_map, x, y, 'x');
		print_result(y, x, ":  hit\n");
		usleep(10000);
		kill(global.pid, SIGUSR2);
	}
}

void modify_array_sender(point_t point, player_t *player)
{
	int y = point.x;
	int x = point.y;

	signal(SIGUSR1, missed);
	signal(SIGUSR2, hit);
	pause();
	if (global.value == 0) {
		set_element_at(player->enemy_map, x, y, 'o');
		print_result(y, x, ":  missed\n");
	}
	if (global.value == 1) {
		set_element_at(player->enemy_map, x, y, 'x');
		print_result(y, x, ":  hit\n");
		global.cross++;
	}
}

void print_result(int x, int y, char *str)
{
	my_putchar(x + 65);
	my_put_nbr(y + 1);
	my_putstr(str);

}

void missed(int a)
{
	(void)a;
	global.value = 0;
}

void hit(int a)
{
	(void)a;
	global.value = 1;
}
