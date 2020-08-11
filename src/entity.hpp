#ifndef ENTITY_H
#define ENTITY_H

// Libraries
#include <SFML/Graphics.hpp>
#include <vector>

// Project files
#include "gameState.hpp"
#include "constants.hpp"
#include "player.hpp"

class Entity
{
public:
    Entity(int x, int y, GameState *state, sf::RenderWindow *renderWindow, Player *targetPlayer, sf::Texture *texture);

    int tileX, tileY;

    void draw();
    virtual void update();

    void drawAll();
    void updateAll();

    static std::vector<Entity*> entityList;
    
private:
    GameState *gameState;
    sf::RenderWindow *window;
    Player *player;
    sf::Texture *entity_Texture;
    sf::Sprite entity_Sprite;
};

#endif