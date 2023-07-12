/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** main file of event manadgement
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#include "window.h"
#include "event.h"

int r_click(sfEvent event);
void manadge_event(sfRenderWindow *window, event_list *list)
{
    sfEvent event;
    reset_event_list(list);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            close_window(window);
        if (right_click(event))
            list -> right_click = 1;
        if (r_click(event))
            list -> r_click = 1;
        if (event.type == sfEvtKeyPressed) {
            list -> key_click = 1;
            list -> key_clicked = event.text.unicode;
        }
    }
}

int r_click(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyR) {
            return 1;
        }
    }
    return 0;
}

int right_click(sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        return 1;
    }
    return 0;
}

void reset_event_list(event_list *list)
{
    list -> right_click = 0;
    list -> r_click = 0;
    list -> key_click = 0;
    list -> key_clicked = -1;
}
