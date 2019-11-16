/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu
*/

#include "../include/menu.h"

void show_menu_background(sfRenderWindow *window)
{
    sfTexture *background_texture = sfTexture_createFromFile("img/background/menu/menubg.png", NULL);
    sfSprite *background_sprite = sfSprite_create();
    sfSprite_setTexture(background_sprite, background_texture, sfTrue);
    sfRenderWindow_drawSprite(window, background_sprite, NULL);
}