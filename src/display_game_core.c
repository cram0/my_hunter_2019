/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** display_game_core
*/

#include "../include/my_hunter.h"

void ajdisplay_game_core(sfRenderWindow *window, game_core *_game_core)
{
    if (_game_core->state == MENU)
        ajdisplay_menu_scene(window, &_game_core->menu_scene);
    if (_game_core->state == INGAME)
        ajdisplay_game_scene(window, &_game_core->game_scene);
    sfRenderWindow_display(window);
}