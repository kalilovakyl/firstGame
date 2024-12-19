#include "raylib.h"

#include "globals.h"
#include "level.h"
#include "player.h"
#include "graphics.h"
#include "assets.h"
#include "utilities.h"

void update_game() {
    game_frame++;
    if (IsKeyPressed(KEY_ESCAPE)) {
        game_state = GAME_STATE_PAUSE;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        move_player_horizontally(MOVEMENT_SPEED);
    }

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        move_player_horizontally(-MOVEMENT_SPEED);
    }

    // Calculating collisions to decide whether the player is allowed to jump: don't want them to suction cup to the ceiling or jump midair
    is_player_on_ground = is_colliding({player_pos.x, player_pos.y + 0.1f}, WALL);
    if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE)) && is_player_on_ground) {
            player_y_velocity = -JUMP_STRENGTH;
    }

    update_player();

}

void draw_game() {
    // TODO

    ClearBackground(BLACK);
    draw_level();
    draw_game_overlay();
}

int main() {
    InitWindow(1800, 800, "Platformer");
    InitAudioDevice();
    SetTargetFPS(60);
    SetExitKey(KEY_Z);
    load_fonts();
    load_images();
    load_sounds();
    load_level();
    load_music();

    while (!WindowShouldClose()) {
        UpdateMusicStream(rain_music);
        BeginDrawing();
        switch (game_state){
        case GAME_STATE_MENU: {
            update_game();
            draw_menu();
            if (IsKeyPressed(KEY_ENTER)){
            game_state = GAME_STATE_PLAY;
            }
            break;
            }
        case GAME_STATE_PLAY:{
            update_game();
            draw_game();
            break;
            }
        case GAME_STATE_PAUSE: {
            draw_game();
            draw_pause_menu();
            if (IsKeyPressed(KEY_ESCAPE)) {
                game_state = GAME_STATE_PLAY;
            }
            break;
            }
        case GAME_STATE_WIN:{
            draw_victory_menu();
            if (IsKeyPressed(KEY_ENTER)) {
                game_state = GAME_STATE_MENU;
            }
            break;
            }
        }
        EndDrawing();
    }

    unload_level();
    unload_sounds();
    unload_images();
    unload_fonts();
    unload_music();

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
