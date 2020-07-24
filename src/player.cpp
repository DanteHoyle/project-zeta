#include <SFML/Graphics.hpp>
#include <iostream>

#include "constants.hpp"
#include "player.hpp"

Player::Player(int startX, int startY, GameState *state, sf::RenderWindow *renderWindow)
{
    tileX = startX;
    tileY = startY;
    gameState = state;
    window = renderWindow;

    if (!playerTexture.loadFromFile("textures/player.png"))
        std::cout << "Error, could not load player texture\n";
    else
        playerSprite.setTexture(playerTexture);

    maxHP = 10;
    currentHP = maxHP;
    level = 1;
    xp = 0;
}

void Player::draw()
{
    playerSprite.setPosition(tileX * SPRITE_SIZE, tileY * SPRITE_SIZE);
    window->draw(playerSprite);
}

void Player::move(int x, int y)
{
    if (!gameState->isSolid(tileX + x, tileY))
        tileX += x;
    
    if (!gameState->isSolid(tileX, tileY + y))
        tileY += y;
}

