/*
** EPITECH PROJECT, 2018
** connection.c
** File description:
** lol
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "prototypes.h"
#include "lib_prototypes.h"
#include "global.h"

global_t global;

void handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)context;
	global.pid = siginfo->si_pid;
}

void connected(int a)
{
	(void)a;
	my_putstr("successfully connected\n");
}
void connection(int nbr, pid_t pid)
{
	struct sigaction act;

	if (nbr == 0) {
		print_connection();
		usleep(10000);
		kill(pid, SIGUSR1);
		global.pid = pid;
		signal(SIGUSR1, connected);
		pause();
	}
	else if (nbr == 1) {
		print_waiting();
		act.sa_sigaction = handler;
		sigemptyset(&act.sa_mask);
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		pause();
		kill(global.pid, SIGUSR1);
		my_putstr("enemy connected\n");
	}
}

void print_waiting(void)
{
	print_connection();
	my_putstr("waiting for enemy connection...\n\n");

}
void print_connection(void)
{
	my_putstr("my_pid: ");
	my_put_nbr(getpid());
	my_putstr("\n");
}
