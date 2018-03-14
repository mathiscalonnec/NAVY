/*
** EPITECH PROJECT, 2018
** read_coordinates.c
** File description:
** read the player input
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "lib_prototypes.h"

char *read_line(void)
{
	char res[1024] = {0};
	char buffer[1] = {0};
	char *line;
	int size = 0;
	int i = 0;

	while ((size = read(STDIN_FILENO, buffer, 1)) && buffer[0] != '\n') {
		res[i] = buffer[0];
		if (size == 0 && res[0] == '\0')
			break;
		i++;
	}
	res[i] = '\0';
	i = 0;
	line = malloc(sizeof(char) * (my_strlen(res) + 1));
	while (res[i] != '\0') {
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int check_input(char *line)
{
	if (my_strlen(line) != 2) {
		my_putstr("wrong position\n");
		return (0);
	}
	if (line[0] < 65 || line [0] > 72) {
		my_putstr("wrong position\n");
		return (0);
	}
	if (line[1] < 49 || line [1] > 56) {
		my_putstr("wrong position\n");
		return (0);
	}
	return (1);
}

point_t read_coordinates(void)
{
	char *line;
	point_t point;

	my_putstr("\nattack:  ");
	line = read_line();
	while (check_input(line) == 0) {
		free(line);
		my_putstr("attack:  ");
		line = read_line();
	}
	point.x = line[0] - 'A';
	point.y = line[1] - '1';
	free(line);
	return (point);
}
