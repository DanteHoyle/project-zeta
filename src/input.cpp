#include "input.hpp"

Input::Input(sf::RenderWindow *renderWindow, sf::View *renderView, GameState *state)
{
    window = renderWindow;
    view = renderView;
    gameState = state;
}

void Input::handleInput()
{
    /**** Keyboard Input *****/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        view->move(0, -4.f);
        window->setView(*view);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        view->move(0, 4.f);
        window->setView(*view);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        view->move(-4.f, 0);
        window->setView(*view);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        view->move(4.f, 0);
        window->setView(*view);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        gameState->clearTiles();
    }

    

    /**** Mouse Input *****/
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

        gameState->setTile(worldPos.x / SPRITE_SIZE, worldPos.y / SPRITE_SIZE, GRASS);
    }
}