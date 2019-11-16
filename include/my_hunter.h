/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

enum game_state{
    MENU, 
    INGAME, 
    PAUSED
    };

void start_game(sfRenderWindow *);

#endif