/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** from the initalisation of reload
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "my.h"
#include "game.h"
#include "src.h"

void fill_text(game *game_data);
int get_sizefile(int file)
{
    int nbr = 0;
    char buffer[1];
    int i = read(file, buffer, 1);
    my_putstr("Read number of word\n");
    while (i == 1) {
        if (buffer[0] == '\n')
            nbr++;
        i = read(file, buffer, 1);
    }
    close(file);
    return nbr;
}

strings *get_string(int file_number)
{
    char buffer[1];
    strings *number;
    egal(&number, "");
    int i = read(file_number, buffer, 1);
    while (buffer[0] != '\n' || i == 0) {
        append(&number, buffer[0]);
        i = read(file_number, buffer, 1);
    }
    return number;
}

void fill_list(strings **list, int nbr)
{
    int file = open(RELOAD_FILE, O_RDONLY);
    strings *temp = get_string(file);
    int i = 0;
    my_putstr("Fill list of word\n");
    while (i < nbr - 1) {
        list[i] = temp;
        temp = get_string(file);
        i++;
    }
    close(file);
}

strings **create_word_list(game *game_data)
{
    int file = open(RELOAD_FILE, O_RDONLY);
    int size_file = get_sizefile(file);
    strings **list = malloc(sizeof(strings *) * size_file);
    game_data -> rel -> nbr_word = size_file;
    fill_list(list, size_file);
    return list;
}

void init_reload(game *game_data)
{
    game_data -> rel = malloc(sizeof(reload));
    game_data -> rel -> word_list = create_word_list(game_data);
    game_data -> rel -> text_deb = sfText_create();
    game_data -> rel -> text_fin = sfText_create();
    game_data -> rel -> type = sfText_create();
    game_data -> rel -> is_reloading = 0;
    game_data -> rel -> nbr_letter_type = 0;
    fill_text(game_data);
    srand(game_data);
}
