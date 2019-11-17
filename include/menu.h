/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu
*/

#ifndef MENU_H
#define MENU_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

typedef struct menu_t {
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
} menu_s;

void show_main_menu_background(sfRenderWindow *);
void show_main_menu(sfRenderWindow *);

#endif