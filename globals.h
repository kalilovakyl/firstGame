#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"
#include "utilities.h"
#include <string>
#include <cstddef>
#include <cmath>

#include "globals.h"

/* Game Elements */

const char WALL      = '#';
const char AIR       = ' ';
const char PLAYER    = '@';
const char COIN      = '*';
const char EXIT      = 'E';
const char THORNS    = 'I';
const char TELEPORT  = 'T';
const char ENEMY     = 'S';
const char BOOTS     = 'B';

/* Levels */

struct level {
    size_t rows = 0, columns = 0;
    char *data = nullptr;
};

char LEVEL_1_DATA[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', '*', ' ', ' ', ' ', ' ', 'S', ' ', ' ', ' ', '#',
    '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#',
    '#', ' ', '@', ' ', 'I', 'I', 'I', '#', 'T', ' ', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
};

level LEVEL_1 = {
    7, 11,
    LEVEL_1_DATA
};

char LEVEL_2_DATA[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#',
    '#', 'T', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', '#', ' ', '#', ' ', 'I', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', '#',
    '#', 'S', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', '#',
    '#', ' ', ' ', '#', '#', ' ', '*', '#', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#',
    '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#',
    '#', 'I', 'I', 'I', ' ', ' ', ' ', '#', '@', ' ', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
};

level LEVEL_2 = {
    12, 11,
    LEVEL_2_DATA
};
char LEVEL_3_DATA[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '#',
    '#', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '#', '#', '#', '#', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'I', '#',
    '#', ' ', ' ', ' ', 'B', '#', '#', '#', '#', 'I', ' ', ' ', ' ', ' ', ' ', 'I', ' ', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
    '#', ' ', '#', ' ', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '#',
    '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#',
    '#', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', '#', '#', 'I', ' ', 'I', 'I', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#',
    '#', ' ', ' ', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', 'T', ' ', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
};

level LEVEL_3 = {
    20, 20,
    LEVEL_3_DATA
};

char LEVEL_4_DATA[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', '#', 'I', 'I', ' ', ' ', ' ', 'I', ' ', ' ', ' ', ' ', ' ', '#',
    '#', '*', '#', '#', '#', '#', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#',
    '#', 'I', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '@', ' ', 'I', 'I', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
};

level LEVEL_4 = {
    15, 15,
    LEVEL_4_DATA
};

char LEVEL_5_DATA[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', '#',
    '#', '#', '#', '#', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#',
    '#', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', 'I', ' ', ' ', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ',
    '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', ' ',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ',
    '#', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ',
    '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ',
    '#', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', ' ', ' ', '#', ' ', ' ', ' ',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' '
};

level LEVEL_5 = {
    15, 18,
    LEVEL_5_DATA
};

int level_index = 0;
const int LEVEL_COUNT = 5;
level LEVELS[LEVEL_COUNT] = {
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    LEVEL_4,
    LEVEL_5,
};


/* Loaded Level Data */

level current_level;
char *current_level_data;

/* Player data */

const float GRAVITY_FORCE = 0.01f;
const float JUMP_STRENGTH = 0.25f;
const float MOVEMENT_SPEED = 0.08f;

Vector2 player_pos;
float player_y_velocity = 0;

bool is_player_on_ground;

int player_score = 0;

Rectangle player_rec = {
    player_pos.x, player_pos.y,
    1.0f, 1.0f
};

// Enemy data

const float ENEMY_MOVEMENT_SPEED = 0.02f;
float enemy_direction = 1; // not const because will be changed

Vector2 enemy_pos;

Rectangle enemy_rec = {
    enemy_pos.x, enemy_pos.y,
    1.0f, 1.0f
};

/* Graphic Metrics */

const float CELL_SCALE = 0.8f; // An aesthetic parameter to add some negative space around level
const float SCREEN_SCALE_DIVISOR = 700.0f; // The divisor was found through experimentation
                                           // to scale things accordingly to look pleasant.

Vector2 screen_size;
float screen_scale; // Used to scale str/UI components size and displacements based on the screen_size size
float cell_size;
Vector2 shift_to_center;

/* Fonts */

Font menu_font;

/* Display Text Parameters */

struct Text {
    std::string str;
    Vector2 position = { 0.50f, 0.50f };
    float size = 32.0f;
    Color color = WHITE;
    float spacing = 4.0f;
    Font* font = &menu_font;
};

Text game_title = {
    "Platformer",
    { 0.50f, 0.50f },
    100.0f,
    YELLOW
};

Text game_subtitle = {
    "Press Enter to Start",
{ 0.50f, 0.65f },
};

Text game_paused = {
    "Press Escape to Resume"
};

Text victory_title = {
    "You Won!",
    { 0.50f, 0.50f },
    100.0f,
    YELLOW
};

Text victory_subtitle = {
    "Press Enter to go back to menu",
    { 0.50f, 0.65f },
    20.0F,
    RED
};

Text game_over_title = {
        "You Lose!",
    {0.50f,0.50f },
          100.0f,
         RED
};
Text game_over_subtitle = {
    "Press Enter to go back to menu",
    { 0.50f, 0.65f }
};

Text escape = {
    "Press Z to exit project",
    {0.48f, 0.75f},
    25.0f,
    BLUE
};

/* Images and Sprites */

Texture2D wall_image;
Texture2D air_image;
Texture2D exit_image;
Texture2D thorns_image;
Texture2D obstacles_image;
Texture2D logo_image;

struct sprite {
    size_t frame_count    = 0;
    size_t frames_to_skip = 3;
    size_t frames_skipped = 0;
    size_t frame_index    = 0;
    bool loop = true;
    size_t prev_game_frame = 0;
    Texture2D *frames = nullptr;
};

sprite coin_sprite;
sprite player_sprite;
sprite teleport_sprite;
sprite enemy_sprite;
sprite double_jump_boots_sprite;

/* Sounds */

Sound coin_sound;
Sound exit_sound;
Sound death_sound;
Sound jump_sound;
Sound teleport_sound;
Sound take_boots_sound;
Sound robot_kills_sound;

Music rain_music;

/* Victory Menu Background */

struct victory_ball {
    float x, y;
    float dx, dy;
    float radius;
};

const size_t VICTORY_BALL_COUNT     = 30;
const float VICTORY_BALL_MAX_SPEED  = 0.8f;
const float VICTORY_BALL_MIN_RADIUS = 10.0f;
const float VICTORY_BALL_MAX_RADIUS = 80.0f;
Color VICTORY_BALL_COLOR[VICTORY_BALL_COUNT];

const unsigned char VICTORY_BALL_TRAIL_TRANSPARENCY = 10;
victory_ball victory_balls[VICTORY_BALL_COUNT];

/* Frame Counter */

size_t game_frame = 0;

/* Game States */

enum game_state {
    GAME_STATE_PLAY,
    GAME_STATE_WIN,
    GAME_STATE_PAUSE,
    GAME_STATE_MENU,
    GAME_OVER_STATE
    // TODO
};
game_state game_state = GAME_STATE_MENU;

/* Forward Declarations */

// GRAPHICS_H

void draw_text(Text &text);
void derive_graphics_metrics_from_loaded_level();
void draw_menu();
void draw_game_overlay();
void draw_level();
void draw_player();
void draw_enemy();
void draw_pause_menu();
void create_victory_menu_background();
void animate_victory_menu_background();
void draw_victory_menu_background();
void draw_victory_menu();

// LEVEL_H

bool is_colliding(Vector2 pos, char look_for = '#', level &level = current_level);
bool is_colliding_thorns(Vector2 pos, char look_for = 'I', level &level = current_level);
bool is_colliding_teleport(Vector2 pos, char look_for = 'E', level &level = current_level);
bool is_colliding_enemy(Vector2 pos, Vector2 pos2, level &level = current_level);
char& get_collider(Vector2 pos, char look_for, level &level = current_level);

void load_level(int offset = 0);
void unload_level();

// PLAYER_H

void spawn_player();
void move_player_horizontally(float delta);
void update_player();

// ENEMY_H

void spawn_enemy();
void update_enemy();

// ASSETS_H

void load_fonts();
void unload_fonts();

void load_images();
void unload_images();

void draw_image(Texture2D image, Vector2 pos, float width, float height);
void draw_image(Texture2D image, Vector2 pos, float size);

sprite load_sprite(
    const std::string &file_name_prefix,
    const std::string &file_name_suffix,
    size_t frame_count = 1,
    bool loop = true,
    size_t frames_to_skip = 3
);
void unload_sprite(sprite &sprite);
void draw_sprite(sprite &sprite, Vector2 pos, float width, float height);
void draw_sprite(sprite &sprite, Vector2 pos, float size);
void draw_sprite_player(sprite &sprite, Vector2 pos, float width, float height);
void draw_sprite_player(sprite &sprite, Vector2 pos, float size);



void load_sounds();
void unload_sounds();

// UTILITIES_H

float rand_from_to(float from, float to);
float rand_up_to(float to);


bool double_jump = false;
int count_double_jumps = 0;

#endif // GLOBALS_H