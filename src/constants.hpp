#ifndef CONSTANTS_H
#define CONSTANTS_H


// Resoluation of each tile
const int SPRITE_SIZE       = 64;

// Max Tile Size
const int TILE_WIDTH        = 256;
const int TILE_HEIGHT       = 256;
const int TILE_AREA = TILE_WIDTH * TILE_HEIGHT;

const int SCREEN_TILE_X = 20;
const int SCREEN_TILE_Y = 15;

// Window constants
const int FRAME_LIMIT       = 60;
const int SCREEN_WIDTH      = SCREEN_TILE_X * SPRITE_SIZE;
const int SCREEN_HEIGHT     = SCREEN_TILE_Y * SPRITE_SIZE;

#endif