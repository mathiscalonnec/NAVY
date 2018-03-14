/*
** EPITECH PROJECT, 2018
** check_file_validity.c
** File description:
** Check if a file is to good format
*/

#include "defines.h"
#include "macros.h"
#include "prototypes.h"

int check_file_validity(char *content)
{
	for (int i = 0; i < BOAT_LIMIT; i++) {
		if (check_parser(content, i) == 0)
			return (0);
		if (check_symbols(content, i) == 0)
			return (0);
		if (content[i * SIZE + 7] != '\n' && i < BOAT_LIMIT - 1)
			return (0);
		if (NUM_TO_INT(content[i * SIZE]) != i + 2)
			return (0);
	}

	return (1);
}

int is_valid_size(char *content, int line)
{
	int i = line * SIZE;
	int h_size = content[i + 5] - content[i + 2];
	int v_size = content[i + 6] - content[i + 3];
	int nb_lines = NUM_TO_INT(content[i]) - 1;

	if (h_size < 0 || v_size < 0)
		return (0);
	if (h_size == 0 && v_size == 0)
		return (0);
	if (h_size != 0 && v_size != 0)
		return (0);
	if (nb_lines != h_size && nb_lines != v_size)
		return (0);

	return (1);
}

int check_parser(char *content, int line)
{
	if (content[line * SIZE + 1] != ':' || content[line * SIZE + 4] != ':')
		return (0);

	return (is_valid_size(content, line));
}

int check_symbols(char *content, int line)
{
	int i = line * SIZE;

	if (IS_CHAR(content[i + 2]) == 0 || IS_CHAR(content[i + 5]) == 0)
		return (0);
	if (IS_NUM(content[i + 3]) == 0 || IS_NUM(content[i + 6]) == 0)
		return (0);

	return (1);
}
