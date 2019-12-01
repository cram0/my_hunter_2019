/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_hunter
*/

#include "../include/my_hunter.h"

int main(int ac, char **av)
{
    sfVideoMode mode = {896, 840, 32};
    sfRenderWindow *window = sfRenderWindow_create
    (mode, "Castlevania | Hunt", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    start_game(window);
    return (0);
}