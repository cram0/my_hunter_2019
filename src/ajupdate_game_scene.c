/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajupdate_game_scene
*/

#include "../include/my_hunter.h"

void ajupdate_game_scene(game_scene *_game_scene, int *_state)
{
    ajupdate_game_scene_music(_game_scene);
    ajupdate_game_event(_game_scene, _state);
    ajupdate_cursor_position(_game_scene);
    ajupdate_mouse_click(_game_scene);
    ajupdate_bat(&_game_scene->bat1);
    ajupdate_bat(&_game_scene->bat2);
}

void ajinitialize_game_background(game_background *_game_background)
{
    _game_background->texture = sfTexture_createFromFile
    ("img/background/gamebg.png", NULL);
    _game_background->sprite = sfSprite_create();
    sfSprite_setTexture(_game_background->sprite,
    _game_background->texture, sfTrue);
    sfSprite_setPosition(_game_background->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(_game_background->sprite, (sfVector2f){3.5, 3.5});
}

void ajupdate_game_scene_music(game_scene *_game_scene)
{
    if (sfMusic_getStatus(_game_scene->music) == sfStopped)
        sfMusic_play(_game_scene->music);
}

void ajupdate_game_event(game_scene *_game_scene, int *_state)
{
    while (sfRenderWindow_pollEvent(_game_scene->window, &_game_scene->event)) {
        if (_game_scene->event.type == sfEvtClosed)
            sfRenderWindow_close(_game_scene->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfMusic_stop(_game_scene->music);
            sfRenderWindow_close(_game_scene->window);
        }
    }
}