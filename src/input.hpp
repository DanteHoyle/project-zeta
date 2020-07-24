#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include "gameState.hpp"
#include "player.hpp"

class Input
{
public:
    Input(sf::RenderWindow *renderWindow, sf::View *renderView, GameState *state, Player *playerp);

    void handleInput();
    void keyDown(sf::Keyboard::Key key);
private:
    sf::RenderWindow *window;
    sf::View *view;
    GameState *gameState;
    Player *player;
};

#endif