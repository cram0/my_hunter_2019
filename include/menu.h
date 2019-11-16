/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu
*/

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.h>

typedef struct menu_t {
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
} menu_s;

void show_menu_background(sfRenderWindow *);

#endif