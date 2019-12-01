/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajdisplay_menu_scene
*/

#include "../include/my_hunter.h"

void ajdisplay_menu_scene(sfRenderWindow *window, menu_scene *_menu_scene)
{
    sfRenderWindow_drawSprite(window,
    _menu_scene->menu_background.sprite, NULL);
    sfRenderWindow_drawSprite(window, _menu_scene->choice.sprite, NULL);
}