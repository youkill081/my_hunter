/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** header to manadge evry event
*/

#ifndef EVENT_H_
    #define EVENT_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
typedef struct event_list {
    int right_click;
    int r_click;
    int key_click;
    int key_clicked;
} event_list;
void manadge_event(sfRenderWindow *window, event_list *list);
int right_click(sfEvent event);
void reset_event_list(event_list *list);
#endif
