/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

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
} game_state ;

enum menu_state {
    PLAY,
    QUIT
} menu_state ;

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
    sfMusic *music;
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
    sfRenderWindow *window;
    sfMusic *music;
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
void ajupdate_bat(bat *);
void ajupdate_bat_position(bat *);
void ajupdate_bat_animation(bat *);
void ajupdate_bat_animation_rectangle(bat *);
void ajupdate_bat_random_spawn_height(bat *);
void ajupdate_bat_random_spawn_side(bat *);
void ajupdate_cursor_position(game_scene *);
void ajupdate_game_core(game_core *);
void ajupdate_game_event(game_scene *, int *);
void ajupdate_game_scene(game_scene *, int *);
void ajupdate_game_scene_music(game_scene *);
void ajupdate_menu_choice_cursor(menu_scene *, int *);
void ajupdate_menu_scene(menu_scene *, int *);
void ajupdate_menu_scene_music(menu_scene *);
void ajupdate_mouse_click(game_scene *);
void ajupdate_mouse_click_check(game_scene *);
void ajupdate_reset_clock(sfClock *);
void ajdisplay_game_core(sfRenderWindow *, game_core *);
void ajdisplay_game_scene(sfRenderWindow *, game_scene *);
void ajdisplay_menu_scene(sfRenderWindow *, menu_scene *);
void ajinitialize_game_core(game_core *, sfRenderWindow *);
void ajinitialize_game_scene (game_scene *, sfRenderWindow *);
void ajinitialize_menu_scene(menu_scene *, sfRenderWindow *);
void ajinitialize_bat(bat *);
void ajupdate_menu_event(menu_scene *, int *)
void ajinitialize_game_background(game_background *);
void ajinitialize_game_cursor(game_cursor *);
void ajinitialize_menu_background(menu_background *);
void ajinitialize_menu_choice_cursor(menu_choice *);
int ajget_state(game_core *);

#endif