/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** Transform a string to number
*/

#include "lib_prototypes.h"

int my_getnbr(char *str)
{
	int a = my_strlen(str) - 1;
	int multi = 1;
	int output = 0;

	while (a >= 0) {
		output += (str[a] - '0') * multi;
		multi = multi * 10;
		a--;
	}

	return (output);
}
