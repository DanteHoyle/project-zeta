#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "constants.hpp"

enum Tiles
{
    EMPTY,
    GRASS,
    WALL
};

class GameState
{
public:
    // draws a tile to the screen
    GameState();

    void drawTile(int x, int y, sf::RenderWindow &window);

    int getTile(int x, int y);
    void setTile(int x, int y, int tile);

    bool isSolid(int x, int y);
    void setSolid(int x, int y, bool solid);

private:
    int tileSet[TILE_AREA];
    bool solidTiles[TILE_AREA];

    sf::Texture t_empty, t_grass, t_wall;
    sf::Sprite s_empty, s_grass, s_wall;
};

#endif