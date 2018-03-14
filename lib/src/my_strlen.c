/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** Count the length of a string
*/

#include "lib_prototypes.h"

int my_strlen(char const *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++);

	return (i);
}
