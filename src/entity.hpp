#ifndef ENTITY_H
#define ENTITY_H

// Libraries
#include <SFML/Graphics.hpp>
#include <vector>

// Project files
#include "gameState.hpp"
#include "constants.hpp"


class Entity
{
public:
    Entity(int x, int y, GameState *state, sf::RenderWindow *renderWindow);

    int tileX, tileY;

    void draw();
    virtual void move();

    static std::vector<Entity*> entityList;
    
private:
    GameState *gameState;
    sf::RenderWindow *window;
    sf::Texture entity_Texture;
    sf::Sprite entity_Sprite;
};

#endif