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
    game_core ggGame_core;
    ajInitialize_game_core(&ggGame_core);
    while (sfRenderWindow_isOpen(window))
    {
        ajUpdate_game_core(&ggGame_core);
        ajDisplay_game_core(window, &ggGame_core);
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_display(window);
    }
}

void ajCheck_state(game_core *_game_core)
{

}

void ajUpdate_game_core(game_core *_game_core)
{
    ajCheck_state(_game_core);
    ajUpdate_game_scene(&_game_core->game_scene);
    ajUpdate_menu_scene(&_game_core->menu_scene);
}

void ajUpdate_game_scene(game_scene *_game_scene)
{
    ajUpdate_bat(&_game_scene->bat1);
    ajUpdate_bat(&_game_scene->bat2);
}

void ajUpdate_bat(bat *_bat)
{
    sfSprite_setPosition(_bat->sprite, (sfVector2f){_bat->x, _bat->y});
    _bat->x++;
    if (_bat->x > WINDOW_WIDTH)
        _bat->x = 0;
}

void ajUpdate_menu_scene(menu_scene *_menu_scene)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        _menu_scene->choice.index = (_menu_scene->choice.index + 1) % 2;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        _menu_scene->choice.index = (_menu_scene->choice.index - 1) % 2;
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && _menu_scene->choice.index == 0) {
        
    }
}

void ajDisplay_game_core(sfRenderWindow *window, game_core *_game_core)
{
    if (_game_core->state == MENU)
        ajDisplay_menu_scene(window, &_game_core->menu_scene);
    if (_game_core->state == INGAME)
        ajDisplay_game_scene(window, &_game_core->game_scene);
}

void ajDisplay_game_scene(sfRenderWindow *window, game_scene *_game_scene)
{
    sfRenderWindow_drawSprite(window, _game_scene->game_background.sprite, NULL);
    sfRenderWindow_drawSprite(window, _game_scene->bat1.sprite, NULL);
}

void ajDisplay_menu_scene(sfRenderWindow *window, menu_scene *_menu_scene)
{
    
}

void ajInitialize_game_core(game_core *_game_core)
{
    _game_core->state = INGAME;
    ajInitialize_game_scene(&_game_core->game_scene);
    ajInitialize_menu_scene(&_game_core->menu_scene);
}

void ajInitialize_game_scene (game_scene *_game_scene)
{
    ajInitialize_bat(&_game_scene->bat1);
    ajInitialize_bat(&_game_scene->bat2);
    ajInitialize_game_background(&_game_scene->game_background);
}

void ajInitialize_bat(bat *_bat)
{
    _bat->rect.left = 0;
    _bat->rect.top = 0;
    _bat->rect.width = 16;
    _bat->rect.height = 29;
    _bat->x = 0;
    _bat->y = 0;
    _bat->texture = sfTexture_createFromFile("img/sprite/bat/bat.png", NULL);
    _bat->sprite = sfSprite_create();
    sfSprite_setTexture(_bat->sprite, _bat->texture, sfTrue);
    sfSprite_setTextureRect(_bat->sprite, _bat->rect);
    sfSprite_setScale(_bat->sprite, (sfVector2f){3.5, 3.5});
}

void ajInitialize_game_background(game_background *_game_background)
{
    _game_background->texture = sfTexture_createFromFile("img/background/ingame/gamebg.png", NULL);
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
    _menu_background->texture = sfTexture_createFromFile("img/background/menu/menubg.png", NULL);
    _menu_background->sprite = sfSprite_create();
    sfSprite_setTexture(_menu_background->sprite, _menu_background->texture, sfTrue);
    sfSprite_setPosition(_menu_background->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(_menu_background->sprite, (sfVector2f){3.5, 3.5});
}

void ajInitialize_menu_choice(menu_choice *_menu_choice)
{
    _menu_choice->index = MENU;
}