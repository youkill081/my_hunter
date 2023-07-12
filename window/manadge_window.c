/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** manadge window
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#include "window.h"
#include "src.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode screen = sfVideoMode_getDesktopMode();
    sfVideoMode mode = {1024, 1024, screen.bitsPerPixel};
    sfRenderWindow* window;
    sfVector2i position = {screen.width / 2 - 512, screen.height / 2 - 512};
    window = sfRenderWindow_create(mode, WINDOW_NAME, sfResize | sfClose, NULL);
    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setPosition(window, position);
    return window;
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

struct fen_data *init_fen(void)
{
    struct fen_data *data = malloc(sizeof(struct fen_data));
    data -> last_width = 1024;
    data -> last_heigth = 1024;
    data -> was_resize = 0;
    return data;
}
