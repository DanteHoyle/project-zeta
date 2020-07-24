#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "gameState.hpp"
#include "constants.hpp"

class Player
{
public:
    Player(int startX, int startY, GameState *state, sf::RenderWindow *renderWindow);
    void move(int x, int y);
    void draw();
    int tileX, tileY, currentHP, maxHP, level, xp;

private:
    GameState *gameState;
    sf::RenderWindow *window;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
};

#endif