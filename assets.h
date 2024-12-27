#ifndef IMAGES_H
#define IMAGES_H

#include "raylib.h"
#include "globals.h"

#include <string>
#include <cassert>

void load_fonts() {
    menu_font = LoadFontEx("data/fonts/ARCADE_N.ttf", 256, nullptr, 128);
}

void unload_fonts() {
    UnloadFont(menu_font);
}

void load_images() {
    wall_image      = LoadTexture("C:/Users/Huawei/CLionProjects/firstGame/data/images/blue_wall.png");
    air_image       = LoadTexture("data/images/air.png");
    exit_image      = LoadTexture("C:/Users/Huawei/CLionProjects/firstGame/data/images/exit.png");
    thorns_image    = LoadTexture("C:/Users/Huawei/CLionProjects/firstGame/data/images/thorns.png");
    logo_image      = LoadTexture("C:/Users/Huawei/CLionProjects/firstGame/data/images/logo.png");
    coin_sprite     = load_sprite("data/images/coin/coin",     ".png", 3, true, 18);
    player_sprite   = load_sprite("C:/Users/Huawei/CLionProjects/firstGame/data/images/player/player", ".png", 4, true, 15);
    teleport_sprite               = load_sprite("C:/Users/Huawei/CLionProjects/firstGame/data/images/teleport/teleport",     ".png", 4, true, 20);
    enemy_sprite                  = load_sprite("C:/Users/Huawei/CLionProjects/firstGame/data/images/star_enemy/star",     ".png", 6, true, 40);
    double_jump_boots_sprite      = load_sprite("C:/Users/Huawei/CLionProjects/firstGame/data/images/double_jump_boots/boots",     ".png", 4, true, 20);
}

void unload_images() {
    UnloadTexture(wall_image);
    UnloadTexture(air_image);
    UnloadTexture(exit_image);
    UnloadTexture(thorns_image);
    UnloadTexture(logo_image);
    unload_sprite(player_sprite);
    unload_sprite(coin_sprite);
    unload_sprite(teleport_sprite);
    unload_sprite(enemy_sprite);
    unload_sprite(double_jump_boots_sprite);
}

void draw_image(Texture2D image, Vector2 pos, float size) {
    draw_image(image, pos, size, size);
}

void draw_image(Texture2D image, Vector2 pos, float width, float height) {
    Rectangle source = { 0.0f, 0.0f, static_cast<float>(image.width), static_cast<float>(image.height) };
    Rectangle destination = { pos.x, pos.y, width, height };
    DrawTexturePro(image, source, destination, { 0.0f, 0.0f }, 0.0f, WHITE);
}
void draw_image_player(Texture2D image, Vector2 pos, float size) {
    draw_image(image, pos, size, size);
}

bool right = true;

float reflect_image = -1.0f;

void draw_image_player(Texture2D image, Vector2 pos, float width, float height) {
    Rectangle source = { 0.0f, 0.0f, static_cast<float>(image.width), static_cast<float>(image.height) };
    if (!right) {
        source.width *= reflect_image;
    }
    Rectangle destination = { pos.x, pos.y, width, height };
    DrawTexturePro(image, source, destination, { 0.0f, 0.0f }, 0.0f, WHITE);
}


sprite load_sprite(
    const std::string &file_name_prefix,
    const std::string &file_name_suffix,
    size_t frame_count,
    bool loop,
    size_t frames_to_skip
) {
    assert(frame_count < 100);

    sprite result = {
        frame_count, frames_to_skip, 0, 0, loop, 0, new Texture2D[frame_count]
    };

    for (size_t i = 0; i < frame_count; ++i) {
        std::string file_name;
        if (frame_count < 10) {
            file_name = file_name_prefix;
            file_name += std::to_string(i);
            file_name += file_name_suffix;
        } else {
            file_name = file_name_prefix;
            file_name += i < 10 ? ("0" + std::to_string(i)) : std::to_string(i);
            file_name += file_name_suffix;
        }
        result.frames[i] = LoadTexture(file_name.c_str());
    }

    return result;
}

void unload_sprite(sprite &sprite) {
    assert(sprite.frames != nullptr);

    for (size_t i = 0; i < sprite.frame_count; ++i) {
        UnloadTexture(sprite.frames[i]);
    }
    delete[] sprite.frames;
    sprite.frames = nullptr;
}

void draw_sprite(sprite &sprite, Vector2 pos, float size) {
    draw_sprite(sprite, pos, size, size);
}

void draw_sprite(sprite &sprite, Vector2 pos, float width, float height) {
    draw_image(sprite.frames[sprite.frame_index], pos, width, height);

    if (sprite.prev_game_frame == game_frame) {
        return;
    }
    if (sprite.frames_skipped < sprite.frames_to_skip) {
        ++sprite.frames_skipped;
    } else {
        sprite.frames_skipped = 0;

        ++sprite.frame_index;
        if (sprite.frame_index >= sprite.frame_count) {
            sprite.frame_index = sprite.loop ? 0 : sprite.frame_count - 1;
        }
    }
    sprite.prev_game_frame = game_frame;
}

void draw_sprite_player(sprite &sprite, Vector2 pos, float size) {
    draw_sprite_player(sprite, pos, size, size);
}

void draw_sprite_player(sprite &sprite, Vector2 pos, float width, float height) {
    draw_image_player(sprite.frames[sprite.frame_index], pos, width, height);

    if (sprite.prev_game_frame == game_frame) {
        return;
    }
    if (sprite.frames_skipped < sprite.frames_to_skip) {
        ++sprite.frames_skipped;
    } else {
        sprite.frames_skipped = 0;

        ++sprite.frame_index;
        if (sprite.frame_index >= sprite.frame_count) {
            sprite.frame_index = sprite.loop ? 0 : sprite.frame_count - 1;
        }
    }
    sprite.prev_game_frame = game_frame;
}

void random_color_for_victory_balls() {
    for (int i = 0; i < VICTORY_BALL_COUNT; ++i) {
        VICTORY_BALL_COLOR[i]  = {     static_cast<unsigned char>(rand_from_to(0, 255)),
                                        static_cast<unsigned char>(rand_from_to(0, 255)),
                                        static_cast<unsigned char>(rand_from_to(0, 255)),
                                        static_cast<unsigned char>(rand_from_to(0, 255)) };
    }
}



void load_sounds() {
    coin_sound     = LoadSound("data/sounds/coin.wav");
    exit_sound     = LoadSound("data/sounds/exit.wav");
    death_sound    = LoadSound("C:/Users/Huawei/CLionProjects/firstGame/data/sounds/death.wav");
    teleport_sound = LoadSound("C:/Users/Huawei/CLionProjects/firstGame/data/sounds/teleport.wav");
    SetSoundVolume(teleport_sound, 4.0f);
    take_boots_sound = LoadSound("C:/Users/Huawei/CLionProjects/firstGame/data/sounds/take_boots.wav");
    SetSoundVolume(take_boots_sound, 4.0f);
    robot_kills_sound = LoadSound("C:/Users/Huawei/CLionProjects/firstGame/data/sounds/robot_kills.wav");
}

void unload_sounds() {
    UnloadSound(coin_sound);
    UnloadSound(exit_sound);
    UnloadSound(death_sound);
    UnloadSound(take_boots_sound);
    UnloadSound(teleport_sound);
}

void load_music() {
    rain_music = LoadMusicStream("C:/Users/Huawei/CLionProjects/firstGame/data/music/rain.mp3");
    SetMusicVolume(rain_music,  0.8f);
    PlayMusicStream(rain_music);
}

void unload_music() {
    UnloadMusicStream(rain_music);
}
#endif // IMAGES_H
