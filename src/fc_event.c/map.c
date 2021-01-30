/*
** EPITECH PROJECT, 2021
** GLOBAS_GAME_JAM_2021
** File description:
** map
*/

#include "../../inc/my.h"

t_game move_background(t_game s_game)
{
    if (s_game.check_pause == 0) {
        s_game.pos_batiment.x = s_game.pos_batiment.x - 0.1;
        sfSprite_setPosition(s_game.s_batiment, s_game.pos_batiment);
        s_game.pos_sol.x = s_game.pos_sol.x - 0.3;
        sfSprite_setPosition(s_game.s_sol, s_game.pos_sol);
    }

    return (s_game);
}

void map(t_window s_window)
{
    t_game s_game = init_map(s_game, s_window);

    while (sfRenderWindow_isOpen(s_game.window)) {
        s_game = get_mouse_map(s_game); 
        //s_game = init_clock_map(s_game);
        sfRenderWindow_display(s_game.window);
        draw_sprite_map(s_game);
        if(sfKeyboard_isKeyPressed(sfKeyEscape))
            s_game.check_pause = 1;
        s_game = click_pause(s_game);
        while (sfRenderWindow_pollEvent(s_game.window, &s_game.event)) {
            close_window(s_game.window, s_game.event);
        }
        s_game = move_rect_map(s_game);
        s_game = move_background(s_game);
    }
}