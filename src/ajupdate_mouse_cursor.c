/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajupdate_mouse_cursor
*/

#include "../include/my_hunter.h"

void ajupdate_mouse_click(game_scene *_game_scene)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfMouse_getPositionRenderWindow(_game_scene->window).x >=
            (_game_scene->bat1.x) && sfMouse_getPositionRenderWindow
            (_game_scene->window).x <= (_game_scene->bat1.x +
            (_game_scene->bat1.rect.width * 3.5))
            && sfMouse_getPositionRenderWindow
            (_game_scene->window).y >= (_game_scene->bat1.y) &&
            sfMouse_getPositionRenderWindow(_game_scene->window).y <=
            (_game_scene->bat1.y + (_game_scene->bat1.rect.height * 3.5))) {
            _game_scene->bat1.reached_end = true;
        }
    }
    ajupdate_mouse_click_check(_game_scene);
}

void ajupdate_mouse_click_check(game_scene *_game_scene)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfMouse_getPositionRenderWindow(_game_scene->window).x >=
            (_game_scene->bat2.x) && sfMouse_getPositionRenderWindow
            (_game_scene->window).x <= (_game_scene->bat2.x +
            (_game_scene->bat2.rect.width * 3.5))
            && sfMouse_getPositionRenderWindow
            (_game_scene->window).y >= (_game_scene->bat2.y) &&
            sfMouse_getPositionRenderWindow(_game_scene->window).y <=
            (_game_scene->bat2.y + (_game_scene->bat2.rect.height * 3.5))) {
            _game_scene->bat2.reached_end = true;
        }
    }
}

void ajupdate_cursor_position(game_scene *_game_scene)
{
    sfRenderWindow_setMouseCursorVisible(_game_scene->window, sfFalse);
    _game_scene->cursor.x =
    sfMouse_getPositionRenderWindow(_game_scene->window).x;
    _game_scene->cursor.y =
    sfMouse_getPositionRenderWindow(_game_scene->window).y;
    sfSprite_setPosition(_game_scene->cursor.sprite, (sfVector2f)
    {_game_scene->cursor.x, _game_scene->cursor.y});
}

void ajupdate_reset_clock(sfClock *_clock)
{
    sfClock_restart(_clock);
}