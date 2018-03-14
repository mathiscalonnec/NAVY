/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** Print all possible integers
*/

#include "lib_prototypes.h"

void my_put_nbr(int nb)
{
	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	if (nb >= 10)
		my_put_nbr(nb / 10);

	my_putchar('0' + nb % 10);
}
