/*
** EPITECH PROJECT, 2022
** index.c
** File description:
** index manadgement for strings lib
*/

#include "strings.h"
#include "my.h"
#include <stddef.h>

char get(strings *string, int index)
{
    strings *temp = string;
    if (string == NULL || len(string) <= index || index < 0) {
        return 0;
    }
    for (int i = 0; i != index; i++) {
        temp = temp -> next;
    }
    return temp -> car;
}

int set(strings *string, int index, char car)
{
    strings *temp = string;
    if (string == NULL || len(string) <= index || index < 0) {
        return 0;
    }
    for (int i = 0; i != index; i++) {
        temp = temp -> next;
    }
    temp -> car = car;
    return 1;
}
