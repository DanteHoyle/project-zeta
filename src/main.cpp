#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "constants.hpp"
#include "gameState.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Project Zeta");

    GameState gameState;
    int counter = 0;

    while (window.isOpen())
    {
        // This block handles events and sends them to the input handler
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    break;
            }
        }

        window.clear(sf::Color::Black);
        for (int i = 0; i < 60; i++)
            for (int j = 0; j < 60; j++)
                gameState.drawTile(j, i, window);

        window.display();

    }
}