/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_hunter
*/

#include "../include/my_hunter.h"

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, 
    "Bat Hunt", sfResize | sfClose, NULL);
    sfWindow_setFramerateLimit(window, 60);
    start_game(window);

    return (0);
}