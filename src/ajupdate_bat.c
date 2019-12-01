/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajupdate_bat
*/

#include "../include/my_hunter.h"

void ajupdate_bat(bat *_bat)
{
    ajupdate_bat_random_spawn_side(_bat);
    ajupdate_bat_random_spawn_height(_bat);
    ajupdate_bat_position(_bat);
    ajupdate_bat_animation(_bat);
    sfSprite_setPosition(_bat->sprite, (sfVector2f){_bat->x, _bat->y});
    ajupdate_reset_clock(_bat->moving_clock);
}

void ajupdate_bat_random_spawn_side(bat *_bat)
{
    if (_bat->reached_end == true) {
        int left_or_right = (rand() % (1 - 0 + 1));
        if (left_or_right == RIGHT)
            _bat->spawn_side = RIGHT;
        else
            _bat->spawn_side = LEFT;
    }
}

void ajupdate_bat_random_spawn_height(bat *_bat)
{
    if (_bat->spawn_side == LEFT)
    {
        if (_bat->reached_end == true) {
            _bat->x = -(_bat->rect.width * 3.5);
            _bat->y = (rand() % (614 - 46 + 1)) + 46;
            _bat->reached_end = false;
        }
        if (_bat->x > (896 + (_bat->rect.width * 3.5)))
            _bat->reached_end = true;
    }
    else if (_bat->spawn_side == RIGHT) {
        if (_bat->reached_end == true) {
            _bat->x = 896 + (_bat->rect.width * 3.5);
            _bat->y = (rand() % (614 - 46 + 1)) + 46;
            _bat->reached_end = false;
        }
        if (_bat->x < (0 - (_bat->rect.width * 3.5)))
            _bat->reached_end = true;
    }
}

void ajupdate_bat_position(bat *_bat)
{
    if (_bat->spawn_side == LEFT)
        _bat->x += 100 * sfTime_asSeconds(
            sfClock_getElapsedTime(_bat->moving_clock));
    else if (_bat->spawn_side == RIGHT)
        _bat->x -= 100 * sfTime_asSeconds(
            sfClock_getElapsedTime(_bat->moving_clock));
}

void ajinitialize_bat(bat *_bat)
{
    _bat->animation_clock = sfClock_create();
    _bat->moving_clock = sfClock_create();
    _bat->spawn_side = LEFT;
    _bat->facing_right = true;
    _bat->going_around = false;
    _bat->reached_end = true;
    _bat->rect.left = 0;
    _bat->rect.top = 0;
    _bat->rect.width = 16;
    _bat->rect.height = 29;
    _bat->x = -32;
    _bat->y = 0;
    _bat->texture = sfTexture_createFromFile("img/sprite/bat/bat.png", NULL);
    _bat->sprite = sfSprite_create();
    sfSprite_setTexture(_bat->sprite, _bat->texture, sfTrue);
    sfSprite_setTextureRect(_bat->sprite, _bat->rect);
}