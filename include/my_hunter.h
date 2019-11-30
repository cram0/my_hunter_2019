/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#define WINDOW_WIDTH 896
#define WINDOW_HEIGHT 840

#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

enum game_state {
    MENU,
    INGAME,
    PAUSED
} enum_state;

typedef struct bat {
    int x;
    int y;
    bool facing_right;
    bool going_around;
    sfSprite *sprite;
    sfTexture *texture;
    sfSound *sound;
    sfIntRect rect;
    sfClock *clock;
} bat ;

typedef struct menu_background {
    sfSprite *sprite;
    sfTexture *texture;
} menu_background ;

typedef struct game_background {
    sfSprite *sprite;
    sfTexture *texture;
} game_background ;

typedef struct game_scene {
    bat bat1;
    bat bat2;
    game_background game_background;
} game_scene ;

typedef struct menu_choice {
    sfSprite *sprite;
    sfTexture *texture;
    int index;
} menu_choice ;

typedef struct menu_scene {
    menu_choice choice;
    menu_background menu_background;
} menu_scene ;

typedef struct game_core {
    int state;
    game_scene game_scene;
    menu_scene menu_scene;
} game_core ;

typedef struct game_ui {

} game_ui;

void start_game(sfRenderWindow *);
int ajGet_state(game_core *);
void ajUpdate_game_core(game_core *);
void ajUpdate_game_scene(game_scene *);
void ajUpdate_bat(bat *);
void ajUpdate_bat_animation(bat *);
void ajUpdate_menu_scene(menu_scene *);
void ajDisplay_game_core(sfRenderWindow *, game_core *);
void ajDisplay_game_scene(sfRenderWindow *, game_scene *);
void ajDisplay_menu_scene(sfRenderWindow *, menu_scene *);
void ajInitialize_game_core(game_core *);
void ajInitialize_game_scene (game_scene *);
void ajInitialize_menu_scene(menu_scene *);
void ajInitialize_bat(bat *);
void ajInitialize_game_background(game_background *);
void ajInitialize_menu_background(menu_background *);
void ajInitialize_menu_choice(menu_choice *);

#endif