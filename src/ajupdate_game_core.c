/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajupdate_game_core
*/

#include "../include/my_hunter.h"

void ajupdate_game_core(game_core *_game_core)
{
    if (ajget_state(_game_core) == MENU)
        ajupdate_menu_scene(&_game_core->menu_scene, &_game_core->state);
    else if (ajget_state(_game_core) == INGAME)
        ajupdate_game_scene(&_game_core->game_scene, &_game_core->state);
}