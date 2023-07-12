/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** the structure for bullet
*/

#ifndef BULLET_H_
    #define BULLET_H_
typedef struct bullet {
    sfImage *bullet_image;
    sfImage *bulletback_image;
    sfTexture *bullet_tex;
    sfTexture *bulletback_tex;
    sfSprite *sprite_image;
    sfSprite *sprite_imageback;
    int is_used;
    sfVector2f pos;
    sfVector2f pos_back;
} bullet;
typedef struct bullet_list {
    bullet *bul1;
    bullet *bul2;
    bullet *bul3;
} bullet_list;
int check_image(bullet *bul);
bullet_list *init_bullet_list(void);
void show_bullet_list(bullet_list *list, sfRenderWindow *window);
void bullet_place(bullet *bul, sfRenderWindow *window);
void remove_bullet(bullet_list *list);
int remain_bullet(bullet_list *list);
#endif
