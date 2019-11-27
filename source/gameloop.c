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
    ajInitialize_game_core(game_core);
    while (sfRenderWindow_isOpen(window) && sfRenderWindow_hasFocus(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            ajUpdate_game_core(game_core);
            ajDisplay_game_core(window, game_core);
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_display(window);
    }
}

void ajCheck_state(game_core _game_core)
{

}

void ajUpdate_game_core(game_core _game_core)
{
    ajCheck_state(_game_core);
    ajUpdate_game_scene(_game_core.game_scene);
    ajUpdate_menu_scene(_game_core.menu_scene);
}

void ajUpdate_game_scene(game_scene _game_scene)
{
    ajUpdate_bat(_game_scene.bat1);
    ajUpdate_bat(_game_scene.bat2);
}

void ajUpdate_bat(bat _bat)
{
    _bat.x++;
    if (_bat.x > WINDOW_WIDTH)
        _bat.x = 0;
}


void ajUpdate_menu_scene(menu_scene _menu_scene)
{

}

void ajDisplay_game_core(sfRenderWindow *window, game_core _game_core)
{

}

void ajInitialize_game_core(game_core _game_core)
{
    _game_core.state = MENU;
    ajInitialize_game_scene(_game_core.game_scene);
    ajInitialize_menu_scene(_game_core.menu_scene);
}

void ajInitialize_game_scene (game_scene _game_scene)
{
    ajInitialize_bat(_game_scene.bat1);
    ajInitialize_bat(_game_scene.bat2);
    ajInitialize_game_background(_game_scene.game_background);
}

void ajInitialize_bat(bat _bat)
{
    _bat.x = 0;
    _bat.y = 0;
    _bat.rect.left = 0;
    _bat.rect.top = 0;
    _bat.rect.width = 16;
    _bat.rect.height = 29;
    _bat.texture = sfTexture_createFromFile("img/sprite/bat/bat.png", NULL);
    _bat.sprite = sfSprite_create();
    sfSprite_setTexture(_bat.sprite, _bat.texture, sfTrue);
    sfSprite_setTextureRect(_bat.sprite, _bat.rect);
}

void ajInitialize_game_background(game_background _game_background)
{
    _game_background.texture = sfTexture_createFromFile("img/background/menu/menubg.png", NULL);
    _game_background.sprite = sfSprite_create();
    sfSprite_setScale(_game_background.sprite, (sfVector2f){2, 2});
    sfSprite_setTexture(_game_background.sprite, _game_background.texture, sfTrue);
}

void ajInitialize_menu_scene(menu_scene _menu_scene)
{
    ajInitialize_menu_background(_menu_scene.menu_background);
    ajInitialize_menu_choice(_menu_scene.choice);
}

void ajInitialize_menu_background(menu_background _menu_background)
{
    _menu_background.texture = sfTexture_createFromFile("img/background/menu/menubg.png", NULL);
    _menu_background.sprite = sfSprite_create();
    sfSprite_setTexture(_menu_background.sprite, _menu_background.texture, sfTrue);
}

void ajInitialize_menu_choice(menu_choice _menu_choice)
{
    _menu_choice.index = 0;
}