/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** for the reload
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "game.h"
#include "reload.h"
#include "event.h"
#include "strings.h"

int letter_is_good(reload *rel, event_list *e)
{
    if (e -> key_clicked + 97 == get(rel->actual_word, rel->nbr_letter_type))
        return 1;
    return 0;
}

void add_good_letter(reload *rel)
{
    strings *write;
    strings *new_string;
    int i = 0;
    egal(&write, "");
    egal(&new_string, "");
    append(&write, get(rel->actual_word, rel -> nbr_letter_type));
    rel -> nbr_letter_type += 1;
    while (i < rel -> nbr_letter_type) {
        set(rel->actual_word, i, ' ');
        i++;
    }
    while (i < len(rel->actual_word)) {
        append(&new_string, get(rel->actual_word, i));
        i++;
    }
    sfText_setString(rel -> text_deb, to_string(write));
    sfText_setString(rel -> text_fin, to_string(new_string));
    sfText_setPosition(rel->text_fin, (sfVector2f) {210, 350});
}

void reload_reset(reload *rel)
{
    rel -> nbr_letter_type = 0;
    rel -> is_reloading = 0;
    sfText_setPosition(rel->text_fin, (sfVector2f) {150, 350});
}

void make_reload(game *game, reload *rel, sfRenderWindow *window, event_list *e)
{
    if (rel -> is_reloading == 0)
        return;
    if (e -> key_click)
        if (letter_is_good(rel, e))
            add_good_letter(rel);
    if (rel->nbr_letter_type == len(rel->first_word)) {
        reload_reset(rel);
        game->bul_list->bul1->is_used = 1;
        game->bul_list->bul2->is_used = 1;
        game->bul_list->bul3->is_used = 1;
    }
    sfRenderWindow_drawText(window, rel->type, NULL);
    sfRenderWindow_drawText(window, rel->text_fin, NULL);
    sfRenderWindow_drawText(window, rel->text_deb, NULL);
    return;
}

void start_reload(reload *rel, event_list *e)
{
    if (rel -> is_reloading == 1)
        return;
    strings *word = rel -> word_list[rand() % rel -> nbr_word + 1];
    rel -> is_reloading = 1;
    rel -> actual_word = word;
    rel -> first_word = word;
    egal(&rel->actual_word_made, "");
    for (int i = 0; i < len(rel->actual_word); i++) {
        append(&rel->actual_word_made, ' ');
    }
    sfText_setString(rel -> text_fin, to_string(rel -> actual_word));
    sfText_setString(rel -> text_deb, to_string(rel -> actual_word_made));
    e -> key_click = 0;
}
