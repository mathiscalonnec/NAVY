/*
** EPITECH PROJECT, 2018
** map_datas_manipulations.c
** File description:
** Manipulations of single line array datas
*/

#include "defines.h"
#include "macros.h"
#include "lib_prototypes.h"
#include "prototypes.h"

char get_element_at(char *content, int x, int y)
{
	return (content[y * SIZE + x]);
}

void set_element_at(char *content, int x, int y, char c)
{
	content[y * SIZE + x] = c;
}

void print_header(void)
{
	my_putstr(" |");
	for (int i = 0; i < SIZE; i++) {
		my_putchar(INT_TO_CHAR(i));
		if (i < SIZE - 1)
			my_putchar(' ');
		else
			my_putchar('\n');
	}
	my_putstr("-+");
	for (int i = 1; i < SIZE << 1; i++)
		my_putchar('-');
	my_putchar('\n');
}

void draw_map(char *map)
{
	print_header();
	for (int i = 0; i < SIZE; i++) {
		my_put_nbr(i + 1);
		my_putchar('|');
		for (int j = 0; j < SIZE; j++) {
			my_putchar(get_element_at(map, i, j));
			if (j < SIZE - 1)
				my_putchar(' ');
		}
		my_putchar('\n');
	}
}

void draw_both_map(player_t *player)
{
	my_putstr("\nmy positions:\n");
	draw_map(player->player_map);
	my_putstr("\nenemy's positions:\n");
	draw_map(player->enemy_map);
}
