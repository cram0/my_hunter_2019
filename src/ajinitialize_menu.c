/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajinitialize_menu
*/

#include "../include/my_hunter.h"

void ajinitialize_menu_scene(menu_scene *_menu_scene, sfRenderWindow *_window)
{
    ajinitialize_menu_background(&_menu_scene->menu_background);
    ajinitialize_menu_choice_cursor(&_menu_scene->choice);
    _menu_scene->event;
    _menu_scene->window = _window;
    _menu_scene->music = sfMusic_createFromFile("music/prayer.ogg");
    sfMusic_setLoop(_menu_scene->music, sfTrue);
    sfMusic_setVolume(_menu_scene->music, 25.0);
    sfMusic_stop(_menu_scene->music);
}

void ajinitialize_menu_background(menu_background *_menu_background)
{
    _menu_background->texture = sfTexture_createFromFile
    ("img/background/menubg.png", NULL);
    _menu_background->sprite = sfSprite_create();
    sfSprite_setTexture(_menu_background->sprite,
    _menu_background->texture, sfTrue);
    sfSprite_setPosition(_menu_background->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(_menu_background->sprite, (sfVector2f){3.5, 3.5});
}

void ajinitialize_menu_choice_cursor(menu_choice *_menu_choice)
{
    _menu_choice->index = PLAY;
    _menu_choice->texture = sfTexture_createFromFile(
        "img/sprite/menu/choice_cursor.png", NULL);
    _menu_choice->sprite = sfSprite_create();
    sfSprite_setTexture(_menu_choice->sprite, _menu_choice->texture, sfTrue);
    sfSprite_setPosition(_menu_choice->sprite, (sfVector2f){220, 470});
    sfSprite_setScale(_menu_choice->sprite, (sfVector2f){2, 2});
}