/*
** EPITECH PROJECT, 2018
** prototypes.h
** File description:
** Prototypes of all functions
*/

#include <signal.h>
#include "player.h"
#include "point.h"

void		print_help(void);
char		*get_file_content(char *filepath);
char		*fill_map_with_dots(void);
void		fill_array_with_datas(char *output, char *content);
int		check_file_validity(char *content);
int		check_parser(char *content, int line);
int		check_symbols(char *content, int line);
char		get_element_at(char *content, int x, int y);
void		set_element_at(char *content, int x, int y, char c);
void		draw_map(char *map);
void		draw_both_map(player_t *player);
char		*create_map(char *filepath);
void		print_header(void);
void		print(int signal);
void		handler(int sig, siginfo_t *siginfo, void *context);
void		connection(int nbr, pid_t pid);
void		print_connection(void);
void		print_waiting(void);
player_t	*init_player(int ac, char **av);
void		free_player(player_t *player);
char		*read_line(void);
int		check_input(char *line);
point_t		read_coordinates(void);
void		send_value(point_t point);
void		incrementation_value(int a);
void		incrementation_stop(int a);
point_t		receive_value(void);
int		game(player_t *player);
int		end_message(player_t *player);
void		modify_array_receiver(point_t point, player_t *player);
void		modify_array_sender(point_t point, player_t *player);
void		missed(int a);
void		hit(int a);
int		end_game(player_t *player);
void		print_result(int x, int y, char *str);
