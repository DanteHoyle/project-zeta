#include "entity.hpp"

Entity::Entity(int x, int y, GameState *state, sf::RenderWindow *renderWindow, Player *targetPlayer, sf::Texture *texture)
{
    // set pointers
    player = targetPlayer;
    gameState = state;
    window = renderWindow;

    tileX = x;
    tileY = y;

    // init texture
    entity_Texture = texture;

    // set texture
    entity_Sprite.setTexture(*entity_Texture);

    entityList.push_back(this);
}

void Entity::draw()
{
    entity_Sprite.setPosition(tileX * SPRITE_SIZE, tileY * SPRITE_SIZE);
    window->draw(entity_Sprite);
}

void Entity::drawAll()
{
    
}