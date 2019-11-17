/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu
*/

#include "../include/menu.h"

void show_main_menu(sfRenderWindow *window)
{
    void show_main_menu_background(window);
}

void create_main_menu()
{
    menu_s menu;
    menu.bg_texture = sfTexture_createFromFile("img/background/menu/menubg.png", NULL);
    menu.bg_sprite = sfSprite_create();
    sfSprite_setTexture(menu.bg_sprite, menu.bg_texture, sfTrue);
}

void show_main_menu_background(sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, menu.bg_sprite, NULL);
}