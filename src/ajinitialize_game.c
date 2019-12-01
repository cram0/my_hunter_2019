/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajinitialize_game
*/

#include "../include/my_hunter.h"

void ajinitialize_game_scene(game_scene *_game_scene, sfRenderWindow *_window)
{
    ajinitialize_bat(&_game_scene->bat1);
    ajinitialize_bat(&_game_scene->bat2);
    ajinitialize_game_background(&_game_scene->game_background);
    ajinitialize_game_cursor(&_game_scene->cursor);
    _game_scene->event;
    _game_scene->window = _window;
    _game_scene->music = sfMusic_createFromFile("music/dracula_castle.ogg");
    sfMusic_setLoop(_game_scene->music, sfTrue);
    sfMusic_setVolume(_game_scene->music, 25.0);
}

void ajinitialize_game_cursor(game_cursor *_cursor)
{
    _cursor->x = 0;
    _cursor->y = 0;
    _cursor->texture = sfTexture_createFromFile
    ("img/sprite/cursor/cursor.png", NULL);
    _cursor->sprite = sfSprite_create();
    sfSprite_setTexture(_cursor->sprite, _cursor->texture, sfTrue);
}