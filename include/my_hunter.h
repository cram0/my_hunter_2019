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
#define GAME_FRAMERATE 60

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

enum game_state {
    MENU,
    INGAME,
    PAUSED
} game_state;

enum bat_spawn_side {
    LEFT,
    RIGHT
} bat_spawn_side;

typedef struct bat {
    int x;
    int y;
    bool spawn_side;
    bool facing_right;
    bool going_around;
    bool reached_end;
    sfSprite *sprite;
    sfTexture *texture;
    sfSound *sound;
    sfIntRect rect;
    sfClock *moving_clock;
    sfClock *animation_clock;
} bat ;

typedef struct menu_background {
    sfSprite *sprite;
    sfTexture *texture;
} menu_background ;

typedef struct game_cursor {
    int x;
    int y;
    sfSprite *sprite;
    sfTexture *texture;
} game_cursor ;

typedef struct game_background {
    sfSprite *sprite;
    sfTexture *texture;
} game_background ;

typedef struct game_scene {
    bat bat1;
    bat bat2;
    game_cursor cursor;
    game_background game_background;
    sfEvent event;
    sfRenderWindow *window;
} game_scene ;

typedef struct menu_choice {
    int index;
    sfSprite *sprite;
    sfTexture *texture;
} menu_choice ;

typedef struct menu_scene {
    menu_choice choice;
    menu_background menu_background;
    sfEvent event;
} menu_scene ;

typedef struct game_core {
    int state;
    sfRenderWindow *window;
    game_scene game_scene;
    menu_scene menu_scene;
} game_core ;

typedef struct game_ui {

} game_ui;

void start_game(sfRenderWindow *);
void ajUpdate_game_core(game_core *);
void ajUpdate_game_scene(game_scene *, int *);
void ajUpdate_cursor(game_scene *);
void ajUpdate_bat(bat *);
void ajUpdate_bat_position(bat *);
void ajUpdate_bat_animation(bat *);
void ajUpdate_bat_animation_rectangle(bat *);
void ajUpdate_bat_random_spawn_height(bat *);
void ajUpdate_bat_random_spawn_side(bat *);
void ajUpdate_game_event(game_scene *);
void ajUpdate_menu_scene(menu_scene *, int *);
void ajUpdate_reset_clock(sfClock *);
void ajDisplay_game_core(sfRenderWindow *, game_core *);
void ajDisplay_game_scene(sfRenderWindow *, game_scene *);
void ajDisplay_menu_scene(sfRenderWindow *, menu_scene *);
void ajInitialize_game_core(game_core *, sfRenderWindow *);
void ajInitialize_game_scene (game_scene *, sfRenderWindow *);
void ajInitialize_menu_scene(menu_scene *);
void ajInitialize_bat(bat *);
void ajInitialize_game_background(game_background *);
void ajInitialize_game_cursor(game_cursor *);
void ajInitialize_menu_background(menu_background *);
void ajInitialize_menu_choice(menu_choice *);
int ajGet_state(game_core *);

#endif