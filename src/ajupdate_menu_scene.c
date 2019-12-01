/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajupdate_menu_scene
*/

#include "../include/my_hunter.h"

void ajupdate_menu_scene(menu_scene *_menu_scene, int *_state)
{
    ajupdate_menu_scene_music(_menu_scene);
    ajupdate_menu_choice_cursor(_menu_scene, _state);
    ajupdate_menu_event(_menu_scene, _state);
}

void ajupdate_menu_choice_cursor(menu_scene *_menu_scene, int *_state)
{
    if (_menu_scene->choice.index == PLAY
    && sfKeyboard_isKeyPressed(sfKeyDown)) {
        _menu_scene->choice.index = QUIT;
        sfSprite_setPosition(_menu_scene->choice.sprite,
        (sfVector2f){220, 540});
    }
    if (_menu_scene->choice.index == QUIT
    && sfKeyboard_isKeyPressed(sfKeyUp)) {
        _menu_scene->choice.index = PLAY;
        sfSprite_setPosition(_menu_scene->choice.sprite,
        (sfVector2f){220, 470});
    }
    if (_menu_scene->choice.index == PLAY
    && sfKeyboard_isKeyPressed(sfKeyEnter)) {
        sfMusic_stop(_menu_scene->music);
        *_state = INGAME;
    }
    if (_menu_scene->choice.index == QUIT
    && sfKeyboard_isKeyPressed(sfKeyEnter))
        sfRenderWindow_close(_menu_scene->window);
}

void ajupdate_menu_scene_music(menu_scene *_menu_scene)
{
    if (sfMusic_getStatus(_menu_scene->music) == sfStopped)
        sfMusic_play(_menu_scene->music);
}

void ajupdate_menu_event(menu_scene *_menu_scene, int *_state)
{
    while (sfRenderWindow_pollEvent(_menu_scene->window, &_menu_scene->event)) {
        if (_menu_scene->event.type == sfEvtClosed)
            sfRenderWindow_close(_menu_scene->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfMusic_stop(_menu_scene->music);
            sfRenderWindow_close(_menu_scene->window);
        }
    }
}
