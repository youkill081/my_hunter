/*
** EPITECH PROJECT, 2022
** my_hunter.c
** File description:
** contain error message
*/

#include "my.h"

void missing_file(char *file_name)
{
    my_putstr("[MISSING FILE] the file \"");
    my_putstr(file_name);
    my_putstr("\" is missing !\n");
}
