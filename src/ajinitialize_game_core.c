/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajinitialize_game_core
*/

#include "../include/my_hunter.h"

void ajinitialize_game_core(game_core *_game_core, sfRenderWindow *_window)
{
    srand(time(NULL));
    _game_core->state = MENU;
    _game_core->window = _window;
    ajinitialize_game_scene(&_game_core->game_scene, _window);
    ajinitialize_menu_scene(&_game_core->menu_scene, _window);
}
