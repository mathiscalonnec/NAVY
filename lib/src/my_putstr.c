/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** Print a sting
*/

#include "lib_prototypes.h"

void my_putstr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
}
