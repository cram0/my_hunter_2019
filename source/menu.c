/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu
*/

#include "../include/menu.h"

void show_menu_background(sfRenderWindow *window)
{
    menu_s menu;
    menu.bg_texture = sfTexture_createFromFile("img/background/menu/menubg.png", NULL);
    menu.bg_sprite = sfSprite_create();
    sfSprite_setTexture(menu.bg_sprite, menu.bg_texture, sfTrue);
    sfRenderWindow_drawSprite(window, menu.bg_sprite, NULL);
}