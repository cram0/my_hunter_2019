/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** gameloop
*/

#include "../include/my_hunter.h"

void start_game(sfRenderWindow *window)
{
    game_core game_core;
    ajinitialize_game_core(&game_core, window);
    while (sfRenderWindow_isOpen(window))
    {
        ajupdate_game_core(&game_core);
        ajdisplay_game_core(window, &game_core);
    }
}