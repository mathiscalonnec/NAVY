/*
** EPITECH PROJECT, 2018
** parse_file.c
** File description:
** Parse file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "defines.h"
#include "macros.h"
#include "lib_prototypes.h"
#include "prototypes.h"

char *get_file_content(char *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char buffer[BUFFER_SIZE];
	int size = read(fd, buffer, BUFFER_SIZE);
	char *output = malloc(sizeof(char) * (size + 1));

	buffer[size] = '\0';
	my_strcpy(output, buffer);

	return (output);
}

char *fill_map_with_dots(void)
{
	char *output = malloc(sizeof(char) * (SIZE * SIZE + 1));

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			set_element_at(output, i, j, BACKGROUND_CHAR);
	}
	output[SIZE * SIZE] = '\0';

	return (output);
}

void fill_array_with_datas(char *output, char *content)
{
	int start_line;
	int end_line;
	int start_col;
	int end_col;
	int range;

	for (int i = 0; i < BOAT_LIMIT; i++) {
		start_line = CHAR_TO_INT(content[(i << 3) + 2]);
		end_line = CHAR_TO_INT(content[(i << 3) + 5]);
		for (; start_line <= end_line; start_line++) {
			start_col = NUM_TO_INT(content[(i << 3) + 3]);
			end_col = NUM_TO_INT(content[(i << 3) + 6]);
			for (; start_col <= end_col; start_col++) {
				range = SIZE * (start_line) + (start_col - 1);
				output[range] = INT_TO_NUM(i + 2);
			}
		}
	}
}

char *create_map(char *filepath)
{
	char *content = get_file_content(filepath);
	char *output;

	if (check_file_validity(content) == 0) {
		free(content);
		return (NULL);
	}
	output = fill_map_with_dots();
	fill_array_with_datas(output, content);
	free(content);

	return (output);
}
