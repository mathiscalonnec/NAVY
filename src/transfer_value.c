/*
** EPITECH PROJECT, 2018
** transfer_value.c
** File description:
** transfer value with signal
*/

#include <signal.h>
#include <unistd.h>
#include "point.h"
#include "global.h"
#include "prototypes.h"

global_t global;

void send_value(point_t point)
{
	int x = 0;
	int y = 0;

	while (x < point.x) {
		usleep(10000);
		kill(global.pid, SIGUSR1);
		x++;
	}
	usleep(10000);
	kill(global.pid, SIGUSR2);
	while (y < point.y) {
		usleep(10000);
		kill(global.pid, SIGUSR1);
		y++;
	}
	usleep(10000);
	kill(global.pid, SIGUSR2);
}

void incrementation_value(int a)
{
	global.value++;
	(void)a;
}

void incrementation_stop(int a)
{
	global.stop++;
	(void)a;
}

point_t receive_value(void)
{
	point_t point;

	global.stop = 0;
	global.value = 0;
	signal(SIGUSR1, incrementation_value);
	signal(SIGUSR2, incrementation_stop);
	while (global.stop == 0)
		pause();
	point.x = global.value;
	global.stop = 0;
	global.value = 0;
	signal(SIGUSR1, incrementation_value);
	signal(SIGUSR2, incrementation_stop);
	while (global.stop == 0)
		pause();
	point.y = global.value;

	return (point);
}
