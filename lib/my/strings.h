/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** for the strings lib
*/

#ifndef STRINGS_H_
    #define STRINGS_H_
typedef struct s {
    char car;
    struct s *next;
} strings;
void append_beg(strings **list, char data);
void egal(strings **str, char *string);
void append(strings **list, char c);
void print(strings *list);
int len(strings *begin);
char *to_string(strings *list);
int contain(strings *str, char car);
int to_int(strings *list);
void append_str(strings **list, char *str);
void append_beg_str(strings **list, char *str);
void println(strings *list);
char get(strings *string, int index);
int set(strings *string, int index, char car);
#endif
