#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "constants.hpp"
#include "gameState.hpp"
#include "input.hpp"
#include "player.hpp"

int main()
{
    // window and view
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Project Zeta");
    sf::View camera(sf::FloatRect(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT));
    window.setView(camera);
    window.setFramerateLimit(FRAME_LIMIT);

    // Game Objects
    GameState gameState;
    Player player(1, 1, &gameState, &window);
    Input input(&window, &camera, &gameState, &player);

    // Game Loop
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
                // Key Down used for player actions
                case sf::Event::KeyPressed:
                    input.keyDown(ev.key.code);
                    break;
            }
        }

        // Get and update player input
        input.handleInput();
        
        // Clear the screen
        window.clear(sf::Color::Black);

        // temporary rendering logic
        for (int i = 0; i < 60; i++)
            for (int j = 0; j < 60; j++)
                gameState.drawTile(j, i, window);
        
        player.draw();

        window.display();
    }
}