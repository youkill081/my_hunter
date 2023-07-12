/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** string lib
*/

#include <stddef.h>
#include <stdlib.h>
#include "strings.h"
#include "my.h"

void egal(strings **str, char *string)
{
    *str == NULL;

    strings *list;
    int i = my_strlen(string) - 1;

    list = NULL;
    while (i >= 0) {
        append_beg(&list, string[i]);
        i--;
    }
    *str = list;
}

int len(strings *begin)
{
    int i = 0;
    strings *tmp = begin;

    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }

    return i;
}

void println(strings *list)
{
    strings *tmp = list;
    while (tmp != NULL) {
        my_putchar(tmp->car);
        tmp = tmp->next;
    }
    my_putchar('\n');
}

void print(strings *list)
{
    strings *tmp = list;
    while (tmp != NULL) {
        my_putchar(tmp->car);
        tmp = tmp->next;
    }
}
