/*
** EPITECH PROJECT, 2018
** macros.h
** File description:
** Macros
*/

#ifndef MACROS_H_
#define MACROS_H_

#define CHAR_TO_INT(x)	(x - 'A')
#define INT_TO_CHAR(x)	(x + 'A')
#define NUM_TO_INT(x)	(x - '0')
#define INT_TO_NUM(x)	(x + '0')
#define IS_CHAR(x)	((x >= 'A' && x <= 'H') ? 1 : 0)
#define IS_NUM(x)	((x >= '0' && x <= '9') ? 1 : 0)

#endif /* MACROS_H_ */
