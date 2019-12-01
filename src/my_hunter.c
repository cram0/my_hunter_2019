/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_hunter
*/

#include "../include/my_hunter.h"

int main(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Bat Hunt", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, GAME_FRAMERATE);
    start_game(window);
    return (0);
}