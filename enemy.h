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
    /*switch (level_index) {
        case 0: {
            enemy_pos.x += ENEMY_MOVEMENT_SPEED * enemy_direction;
            break;
        }
        case 1:
            case 2:
        case 3:
        case 4:
        {
            enemy_pos.y += ENEMY_MOVEMENT_SPEED * enemy_direction;
            enemy_rec.y = enemy_pos.y;
            break;
        }
    }
    if (is_colliding(enemy_pos, WALL)) {
        enemy_direction *= -1;
    }*/
};

#endif //ENEMY_H