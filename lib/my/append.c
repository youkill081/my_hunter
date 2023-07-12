/*
** EPITECH PROJECT, 2022
** strings.c
** File description:
** all apend beg
*/

#include <stdlib.h>
#include "strings.h"

void append_beg(strings **list, char data)
{
    strings *new_list;

    new_list = malloc(sizeof(strings));
    new_list->car = data;
    new_list->next = *list;
    *list = new_list;
}

void append(strings **list, char c)
{
    if (*list == NULL) {
        append_beg(list, c);
        return;
    }
    strings *tmp = *list;
    while (tmp -> next != NULL)
        tmp = tmp -> next;
    strings *new;
    new = malloc(sizeof(strings));
    new -> car = c;
    new -> next = NULL;
    tmp -> next = new;
}

void append_str(strings **list, char *str)
{
    strings *str2;
    strings *tmp = *list;

    if (*list == NULL) {
        egal(list, str);
        return;
    }
    egal(&str2, str);
    while (tmp -> next != NULL)
        tmp = tmp -> next;

    tmp->next = str2;
}

void append_beg_str(strings **list, char *str)
{
    strings *str2;
    strings *beg;
    egal(&str2, str);
    beg = str2;
    while (str2 -> next != NULL)
        str2 = str2 -> next;
    str2 -> next = *list;
    *list = beg;
}
