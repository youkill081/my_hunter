/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for the reload
*/

#ifndef RELOAD_H_
    #define RELOAD_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include "game.h"
    #include "strings.h"
    #include "event.h"
typedef struct reload {
    strings **word_list;
    sfText *text_deb;
    sfText *text_fin;
    sfText *type;
    int is_reloading;
    int nbr_word;
    int nbr_letter_type;
    strings *actual_word;
    strings *actual_word_made;
    strings *first_word;
} reload;
void start_reload(reload *rel, event_list *e);
#endif
