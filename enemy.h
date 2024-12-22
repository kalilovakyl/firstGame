#ifndef ENEMY_H
#define ENEMY_H

#include "globals.h"

void spawn_enemy() {
    for (size_t row = 0; row < current_level.rows; ++row) {
        for (size_t column = 0; column < current_level.columns; ++column) {
            char cell = current_level.data[row * current_level.columns + column];
            if (cell == ENEMY) {
                enemy_pos.x = static_cast<float>(column);
                enemy_pos.y = static_cast<float>(row);
                return;
            }
        }
    }
}

void update_enemy(){
    enemy_pos.x += ENEMY_MOVEMENT_SPEED * enemy_direction;
    if (is_colliding(enemy_pos, WALL)) {
        enemy_direction *= -1;
    }
};

#endif //ENEMY_H
