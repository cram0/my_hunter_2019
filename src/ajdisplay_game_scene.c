/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajdisplay_game_scene
*/

#include "../include/my_hunter.h"

void ajdisplay_game_scene(sfRenderWindow *window, game_scene *_game_scene)
{
    sfRenderWindow_drawSprite(window,
    _game_scene->game_background.sprite, NULL);
    sfRenderWindow_drawSprite(window, _game_scene->bat1.sprite, NULL);
    sfRenderWindow_drawSprite(window, _game_scene->bat2.sprite, NULL);
    sfRenderWindow_drawSprite(window, _game_scene->cursor.sprite, NULL);
}