#include "gameState.hpp"
#include "constants.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

GameState::GameState()
{
    clearTiles();

    // Load textures to memory
    if (!t_empty.loadFromFile("textures/empty.png"))
    {
        std::cout << "Error, could not load empty.png\n";
    }

    if (!t_grass.loadFromFile("textures/grass.png"))
    {
        std::cout << "Error, could not load grass.png\n";
    }

    if (!t_wall.loadFromFile("textures/wall.png"))
    {
        std:: cout << "Error, could not load wall.png\n";
    }

    // loads sprites with textures
    s_empty.setTexture(t_empty);
    s_grass.setTexture(t_grass);
    s_wall.setTexture(t_wall);

}

// Basic getters and setters
int GameState::getTile(int x, int y)
{
    return tileSet[x + TILE_WIDTH * y];
}

void GameState::setTile(int x, int y, int tile)
{
    tileSet[x + TILE_WIDTH * y] = tile;
}

bool GameState::isSolid(int x, int y)
{
    return solidTiles[x + TILE_WIDTH * y];
}

void GameState::setSolid(int x, int y, bool solid)
{
    solidTiles[x + y * TILE_WIDTH] = solid;
}

void GameState::drawTile(int x, int y, sf::RenderWindow &window)
{
    sf::Sprite *drawTile = nullptr;

    switch(tileSet[x + TILE_WIDTH * y])
    {
        case EMPTY:
            drawTile = &s_empty;
            break;

        case GRASS:
            drawTile = &s_grass;
            break;
        case WALL:
            drawTile = &s_wall;
            break;
    }

    drawTile->setPosition(x * SPRITE_SIZE, y * SPRITE_SIZE);
    window.draw(*drawTile);
}

void GameState::clearTiles()
{
    for (int i = 0; i < TILE_AREA; i++)
    {
        tileSet[i] = EMPTY;
        solidTiles[i] = false;
    }
}