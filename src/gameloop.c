/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** gameloop
*/

#include "../include/my_hunter.h"

void start_game(sfRenderWindow *window)
{
    sfEvent event;
    game_core game_core;
    ajInitialize_game_core(&game_core, window);
    while (sfRenderWindow_isOpen(window))
    {
        ajUpdate_game_core(&game_core);
        ajDisplay_game_core(window, &game_core);
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
    }
}

int ajGet_state(game_core *_game_core)
{
    return (_game_core->state);
}

void ajUpdate_game_core(game_core *_game_core)
{
    if (ajGet_state(_game_core) == MENU)
        ajUpdate_menu_scene(&_game_core->menu_scene, &_game_core->state);
    else if (ajGet_state(_game_core) == INGAME)
        ajUpdate_game_scene(&_game_core->game_scene, &_game_core->state);
}

void ajUpdate_game_scene(game_scene *_game_scene, int *_state)
{
    ajUpdate_game_event(_game_scene);
    ajUpdate_cursor(_game_scene);
    ajUpdate_bat(&_game_scene->bat1);
    ajUpdate_bat(&_game_scene->bat2);
}

void ajUpdate_game_event(game_scene *_game_scene)
{
    if (_game_scene->event.mouseButton.type == sfEvtMouseButtonPressed)
        printf("lol");
}

void ajUpdate_cursor(game_scene *_game_scene)
{
    sfRenderWindow_setMouseCursorVisible(_game_scene->window, sfFalse);
    _game_scene->cursor.x = sfMouse_getPositionRenderWindow(_game_scene->window).x;
    _game_scene->cursor.y = sfMouse_getPositionRenderWindow(_game_scene->window).y;
    sfSprite_setPosition(_game_scene->cursor.sprite, (sfVector2f){_game_scene->cursor.x, _game_scene->cursor.y});
}

void ajUpdate_bat(bat *_bat)
{
    ajUpdate_bat_random_spawn_side(_bat);
    ajUpdate_bat_random_spawn_height(_bat);
    ajUpdate_bat_position(_bat);
    ajUpdate_bat_animation(_bat);
    sfSprite_setPosition(_bat->sprite, (sfVector2f){_bat->x, _bat->y});
    ajUpdate_reset_clock(_bat->moving_clock);
}

void ajUpdate_bat_random_spawn_side(bat *_bat)
{
    if (_bat->reached_end == true) {
        int left_or_right = (rand() % (1 - 0 + 1));
        if (left_or_right == RIGHT)
            _bat->spawn_side = RIGHT;
        else
            _bat->spawn_side = LEFT;
    }
}

void ajUpdate_bat_random_spawn_height(bat *_bat)
{
    if (_bat->spawn_side == LEFT)
    {
        if (_bat->reached_end == true) {
            _bat->x = -(_bat->rect.width * 3.5);
            _bat->y = (rand() % (614 - 46 + 1)) + 46;
            _bat->reached_end = false;
        }
        if (_bat->x > (WINDOW_WIDTH + (_bat->rect.width * 3.5)))
            _bat->reached_end = true;
    }
    else if (_bat->spawn_side == RIGHT) {
        if (_bat->reached_end == true) {
            _bat->x = WINDOW_WIDTH + (_bat->rect.width * 3.5);
            _bat->y = (rand() % (614 - 46 + 1)) + 46;
            _bat->reached_end = false;
        }
        if (_bat->x < (0 - (_bat->rect.width * 3.5)))
            _bat->reached_end = true;
    }
}

void ajUpdate_bat_position(bat *_bat)
{
    if (_bat->spawn_side == LEFT)
        _bat->x += 500 * sfTime_asSeconds(sfClock_getElapsedTime(_bat->moving_clock));
    else if (_bat->spawn_side == RIGHT)
        _bat->x -= 500 * sfTime_asSeconds(sfClock_getElapsedTime(_bat->moving_clock));
}

void ajUpdate_bat_animation(bat *_bat)
{
    if (_bat->facing_right == true && _bat->spawn_side == LEFT)
        sfSprite_setScale(_bat->sprite, (sfVector2f){-3.5, 3.5});
    else
        sfSprite_setScale(_bat->sprite, (sfVector2f){3.5, 3.5});
    if (sfTime_asSeconds(sfClock_getElapsedTime(_bat->animation_clock)) > 0.050) {
        ajUpdate_bat_animation_rectangle(_bat);
        ajUpdate_reset_clock(_bat->animation_clock);
    }
    sfSprite_setTextureRect(_bat->sprite, _bat->rect);
}

void ajUpdate_bat_animation_rectangle(bat *_bat)
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

void ajUpdate_reset_clock(sfClock *_clock)
{
    sfClock_restart(_clock);
}

void ajUpdate_menu_scene(menu_scene *_menu_scene, int *_state)
{

}

void ajDisplay_game_core(sfRenderWindow *window, game_core *_game_core)
{
    if (_game_core->state == MENU)
        ajDisplay_menu_scene(window, &_game_core->menu_scene);
    if (_game_core->state == INGAME)
        ajDisplay_game_scene(window, &_game_core->game_scene);
    sfRenderWindow_display(window);
}

void ajDisplay_game_scene(sfRenderWindow *window, game_scene *_game_scene)
{
    sfRenderWindow_drawSprite(window, _game_scene->game_background.sprite, NULL);
    sfRenderWindow_drawSprite(window, _game_scene->bat1.sprite, NULL);
    sfRenderWindow_drawSprite(window, _game_scene->bat2.sprite, NULL);
    sfRenderWindow_drawSprite(window, _game_scene->cursor.sprite, NULL);
}

void ajDisplay_menu_scene(sfRenderWindow *window, menu_scene *_menu_scene)
{
    sfRenderWindow_drawSprite(window, _menu_scene->menu_background.sprite, NULL);
}

void ajInitialize_game_core(game_core *_game_core, sfRenderWindow *_window)
{
    srand(time(NULL));
    _game_core->state = INGAME;
    _game_core->window = _window;
    ajInitialize_game_scene(&_game_core->game_scene, _window);
    ajInitialize_menu_scene(&_game_core->menu_scene);
}

void ajInitialize_game_scene (game_scene *_game_scene, sfRenderWindow *_window)
{
    ajInitialize_bat(&_game_scene->bat1);
    ajInitialize_bat(&_game_scene->bat2);
    ajInitialize_game_background(&_game_scene->game_background);
    ajInitialize_game_cursor(&_game_scene->cursor);
    _game_scene->event;
    _game_scene->window = _window;
}

void ajInitialize_game_cursor(game_cursor *_cursor)
{
    _cursor->x = 0;
    _cursor->y = 0;
    _cursor->texture = sfTexture_createFromFile("img/sprite/cursor/cursor.png", NULL);
    _cursor->sprite = sfSprite_create();
    sfSprite_setTexture(_cursor->sprite, _cursor->texture, sfTrue);
}

void ajInitialize_bat(bat *_bat)
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

void ajInitialize_game_background(game_background *_game_background)
{
    _game_background->texture = sfTexture_createFromFile("img/background/gamebg.png", NULL);
    _game_background->sprite = sfSprite_create();
    sfSprite_setTexture(_game_background->sprite, _game_background->texture, sfTrue);
    sfSprite_setPosition(_game_background->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(_game_background->sprite, (sfVector2f){3.5, 3.5});
}

void ajInitialize_menu_scene(menu_scene *_menu_scene)
{
    ajInitialize_menu_background(&_menu_scene->menu_background);
    ajInitialize_menu_choice(&_menu_scene->choice);
}

void ajInitialize_menu_background(menu_background *_menu_background)
{
    _menu_background->texture = sfTexture_createFromFile("img/background/menubg.png", NULL);
    _menu_background->sprite = sfSprite_create();
    sfSprite_setTexture(_menu_background->sprite, _menu_background->texture, sfTrue);
    sfSprite_setPosition(_menu_background->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(_menu_background->sprite, (sfVector2f){3.5, 3.5});
}

void ajInitialize_menu_choice(menu_choice *_menu_choice)
{
    _menu_choice->index = MENU;
}