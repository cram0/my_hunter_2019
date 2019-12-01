/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** gameloop
*/

#include "../include/my_hunter.h"

void start_game(sfRenderWindow *window)
{
    game_core game_core;
    ajinitialize_game_core(&game_core, window);
    while (sfRenderWindow_isOpen(window))
    {
        ajupdate_game_core(&game_core);
        ajdisplay_game_core(window, &game_core);
    }
}

int ajget_state(game_core *_game_core)
{
    return (_game_core->state);
}

void ajupdate_game_core(game_core *_game_core)
{
    if (ajget_state(_game_core) == MENU)
        ajupdate_menu_scene(&_game_core->menu_scene, &_game_core->state);
    else if (ajget_state(_game_core) == INGAME)
        ajupdate_game_scene(&_game_core->game_scene, &_game_core->state);
}

void ajupdate_game_scene(game_scene *_game_scene, int *_state)
{
    ajupdate_game_scene_music(_game_scene);
    ajupdate_game_event(_game_scene, _state);
    ajupdate_cursor_position(_game_scene);
    ajupdate_bat(&_game_scene->bat1);
    ajupdate_bat(&_game_scene->bat2);
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
            *_state = MENU;
            sfMusic_stop(_game_scene->music);
        }
    }
}

void ajupdate_menu_event(menu_scene *_menu_scene, int *_state)
{
    while(sfRenderWindow_pollEvent(_menu_scene->window, &_menu_scene->event)) {
        if (_menu_scene->event.type == sfEvtClosed)
            sfRenderWindow_close(_menu_scene->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            *_state = INGAME;
            sfMusic_stop(_menu_scene->music);
        }
    }
}

void ajupdate_cursor_position(game_scene *_game_scene)
{
    sfRenderWindow_setMouseCursorVisible(_game_scene->window, sfFalse);
    _game_scene->cursor.x = sfMouse_getPositionRenderWindow(_game_scene->window).x;
    _game_scene->cursor.y = sfMouse_getPositionRenderWindow(_game_scene->window).y;
    sfSprite_setPosition(_game_scene->cursor.sprite, (sfVector2f){_game_scene->cursor.x, _game_scene->cursor.y});
}

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

void ajupdate_bat_position(bat *_bat)
{
    if (_bat->spawn_side == LEFT)
        _bat->x += 500 * sfTime_asSeconds(sfClock_getElapsedTime(_bat->moving_clock));
    else if (_bat->spawn_side == RIGHT)
        _bat->x -= 500 * sfTime_asSeconds(sfClock_getElapsedTime(_bat->moving_clock));
}

void ajupdate_bat_animation(bat *_bat)
{
    if (_bat->facing_right == true && _bat->spawn_side == LEFT)
        sfSprite_setScale(_bat->sprite, (sfVector2f){-3.5, 3.5});
    else
        sfSprite_setScale(_bat->sprite, (sfVector2f){3.5, 3.5});
    if (sfTime_asSeconds(sfClock_getElapsedTime(_bat->animation_clock)) > 0.050) {
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

void ajupdate_reset_clock(sfClock *_clock)
{
    sfClock_restart(_clock);
}

void ajupdate_menu_scene(menu_scene *_menu_scene, int *_state)
{
    ajupdate_menu_scene_music(_menu_scene);
    ajupdate_menu_event(_menu_scene, _state);
}

void ajupdate_menu_scene_music(menu_scene *_menu_scene)
{
    if (sfMusic_getStatus(_menu_scene->music) == sfStopped)
        sfMusic_play(_menu_scene->music);
}

void ajdisplay_game_core(sfRenderWindow *window, game_core *_game_core)
{
    if (_game_core->state == MENU)
        ajdisplay_menu_scene(window, &_game_core->menu_scene);
    if (_game_core->state == INGAME)
        ajdisplay_game_scene(window, &_game_core->game_scene);
    sfRenderWindow_display(window);
}

void ajdisplay_game_scene(sfRenderWindow *window, game_scene *_game_scene)
{
    sfRenderWindow_drawSprite(window, _game_scene->game_background.sprite, NULL);
    sfRenderWindow_drawSprite(window, _game_scene->bat1.sprite, NULL);
    sfRenderWindow_drawSprite(window, _game_scene->bat2.sprite, NULL);
    sfRenderWindow_drawSprite(window, _game_scene->cursor.sprite, NULL);
}

void ajdisplay_menu_scene(sfRenderWindow *window, menu_scene *_menu_scene)
{
    sfRenderWindow_drawSprite(window, _menu_scene->menu_background.sprite, NULL);
    sfRenderWindow_drawSprite(window, _menu_scene->choice.sprite, NULL);
}

void ajinitialize_game_core(game_core *_game_core, sfRenderWindow *_window)
{
    srand(time(NULL));
    _game_core->state = MENU;
    _game_core->window = _window;
    ajinitialize_game_scene(&_game_core->game_scene, _window);
    ajinitialize_menu_scene(&_game_core->menu_scene, _window);
}

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
    _cursor->texture = sfTexture_createFromFile("img/sprite/cursor/cursor.png", NULL);
    _cursor->sprite = sfSprite_create();
    sfSprite_setTexture(_cursor->sprite, _cursor->texture, sfTrue);
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

void ajinitialize_game_background(game_background *_game_background)
{
    _game_background->texture = sfTexture_createFromFile("img/background/gamebg.png", NULL);
    _game_background->sprite = sfSprite_create();
    sfSprite_setTexture(_game_background->sprite, _game_background->texture, sfTrue);
    sfSprite_setPosition(_game_background->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(_game_background->sprite, (sfVector2f){3.5, 3.5});
}

void ajinitialize_menu_scene(menu_scene *_menu_scene, sfRenderWindow *_window)
{
    ajinitialize_menu_background(&_menu_scene->menu_background);
    ajinitialize_menu_choice(&_menu_scene->choice);
    _menu_scene->event;
    _menu_scene->window = _window;
    _menu_scene->music = sfMusic_createFromFile("music/prayer.ogg");
    sfMusic_setLoop(_menu_scene->music, sfTrue);
    sfMusic_setVolume(_menu_scene->music, 25.0);
    sfMusic_stop(_menu_scene->music);
}

void ajinitialize_menu_background(menu_background *_menu_background)
{
    _menu_background->texture = sfTexture_createFromFile("img/background/menubg.png", NULL);
    _menu_background->sprite = sfSprite_create();
    sfSprite_setTexture(_menu_background->sprite, _menu_background->texture, sfTrue);
    sfSprite_setPosition(_menu_background->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(_menu_background->sprite, (sfVector2f){3.5, 3.5});
}

void ajinitialize_menu_choice(menu_choice *_menu_choice)
{
    _menu_choice->index = INGAME;
    _menu_choice->texture = sfTexture_createFromFile("img/sprite/menu/choice_cursor.png", NULL);
    _menu_choice->sprite = sfSprite_create();
    sfSprite_setTexture(_menu_choice->sprite, _menu_choice->texture, sfTrue);
    sfSprite_setPosition(_menu_choice->sprite, (sfVector2f){0.0, 0.0});
    sfSprite_setScale(_menu_choice->sprite, (sfVector2f){2, 2});
}