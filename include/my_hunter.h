/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 750

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

enum game_state{
    MENU,
    INGAME,
    PAUSED
};

typedef struct bat {
    int x;
    int y;
    sfSprite *sprite;
    sfTexture *texture;
    sfSound *sound;
    sfIntRect rect;
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

typedef struct menu_scene {
    int choice;
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

#endif