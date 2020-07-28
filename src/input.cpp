#include "input.hpp"

Input::Input(sf::RenderWindow *renderWindow, sf::View *renderView, GameState *state, Player *playerp)
{
    window = renderWindow;
    view = renderView;
    gameState = state;
    player = playerp;
}

void Input::handleInput()
{
    /**** Keyboard Input *****/
    // camera movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        view->move(0, -4.f);
        window->setView(*view);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        view->move(0, 4.f);
        window->setView(*view);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        view->move(-4.f, 0);
        window->setView(*view);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        view->move(4.f, 0);
        window->setView(*view);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        gameState->clearTiles();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

        gameState->setTile(worldPos.x / SPRITE_SIZE, worldPos.y / SPRITE_SIZE, WALL);
        gameState->setSolid(worldPos.x / SPRITE_SIZE, worldPos.y / SPRITE_SIZE, true);
    }
    
    /**** Mouse Input *****/
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

        gameState->setTile(worldPos.x / SPRITE_SIZE, worldPos.y / SPRITE_SIZE, GRASS);
        gameState->setSolid(worldPos.x / SPRITE_SIZE, worldPos.y / SPRITE_SIZE, false);
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

        gameState->setTile(worldPos.x / SPRITE_SIZE, worldPos.y / SPRITE_SIZE, EMPTY);
        gameState->setSolid(worldPos.x / SPRITE_SIZE, worldPos.y / SPRITE_SIZE, false);

    }
}

void Input::keyDown(sf::Keyboard::Key key)
{
    switch(key)
    {
        case sf::Keyboard::Up:
            player->move(0, -1);
            break;
        case sf::Keyboard::Down:
            player->move(0, 1);
            break;
        case sf::Keyboard::Left:
            player->move(-1, 0);
            break;
        case sf::Keyboard::Right:
            player->move(1, 0);
            break;
    }
}