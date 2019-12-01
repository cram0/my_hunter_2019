/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** ajupdate_bat_animation
*/

#include "../include/my_hunter.h"

void ajupdate_bat_animation(bat *_bat)
{
    if (_bat->facing_right == true && _bat->spawn_side == LEFT)
        sfSprite_setScale(_bat->sprite, (sfVector2f){-3.5, 3.5});
    else
        sfSprite_setScale(_bat->sprite, (sfVector2f){3.5, 3.5});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(_bat->animation_clock)) > 0.050) {
        ajupdate_bat_animation_rectangle(_bat);
        ajupdate_reset_clock(_bat->animation_clock);
    }
    sfSprite_setTextureRect(_bat->sprite, _bat->rect);
}

void ajupdate_bat_animation_rectangle(bat *_bat)
{
    if (_bat->going_around == false) {
        _bat->rect.left += 16;
        if (_bat->rect.left == 96)
            _bat->going_around = true;
    }
    if (_bat->going_around == true) {
        _bat->rect.left -= 16;
        if (_bat->rect.left == 0)
            _bat->going_around = false;
    }
}