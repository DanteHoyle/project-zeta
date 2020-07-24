#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include "gameState.hpp"

class Input
{
public:
    Input(sf::RenderWindow *renderWindow, sf::View *renderView, GameState *state);

    void handleInput();
private:
    sf::RenderWindow *window;
    sf::View *view;
    GameState *gameState;
    
};

#endif