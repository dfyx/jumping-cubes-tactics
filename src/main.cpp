
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>

#include "gamedata/game.h"
#include "gamedata/player.h"
#include "gamelogic/turncontroller.h"
#include "graphics/node_sprite.h"
#include "graphics/edge_sprite.h"

#include "loaders/simple_game_loader.h"

#include <iostream>

using namespace JCT_SFML;


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    // Request a 32-bits depth buffer when creating the window
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 32;
    contextSettings.antialiasingLevel = 8;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1280, 800), "JCT-SFML", sf::Style::Default, contextSettings);
    window.setVerticalSyncEnabled(true);

    Loaders::SimpleGameLoader loader("data/risk.jct");

    std::vector<Graphics::NodeSprite*> nodeSprites = loader.nodeSprites();
    std::vector<Graphics::EdgeSprite*> edgeSprites = loader.edgeSprites();

    Gamedata::Game *game = loader.game();
    game->addPlayer("Player 1", 0xFF, 0x00, 0x00);
    game->addPlayer("Player 2", 0x66, 0x66, 0xFF);
    game->addPlayer("Player 3", 0x00, 0xFF, 0x00);
    game->addPlayer("Player 4", 0xFF, 0x00, 0xFF);

    Gamelogic::Turncontroller controller(game);

    Graphics::NodeSprite *highlightedNode = NULL;

    // Start game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Escape key : exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        // Handle mouse input
        {
            if(highlightedNode != NULL)
            {
                highlightedNode->setHighlighted(false);
                highlightedNode = NULL;
            }

            sf::Vector2i intMousePos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos(intMousePos.x, intMousePos.y);
            std::vector<Graphics::NodeSprite*>::iterator nodeIter;
            for(nodeIter = nodeSprites.begin(); nodeIter != nodeSprites.end(); nodeIter++)
            {
                Graphics::NodeSprite *nodeSprite = (*nodeIter);
                if(nodeSprite->collides(mousePos) && controller.canIncreaseNode(nodeSprite->node()))
                {
                    highlightedNode = nodeSprite;
                    nodeSprite->setHighlighted(true);

                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && controller.increaseNode(nodeSprite->node()))
                    {
                        controller.startNextTurn();
                    }
                    break;
                }
            }
        }

        window.clear();

        // Draw edges and nodes
        {
            std::vector<Graphics::EdgeSprite*>::iterator edgeIter;
            for(edgeIter = edgeSprites.begin(); edgeIter != edgeSprites.end(); edgeIter++)
            {
                window.draw(**edgeIter);
            }

            std::vector<Graphics::NodeSprite*>::iterator nodeIter;
            for(nodeIter = nodeSprites.begin(); nodeIter != nodeSprites.end(); nodeIter++)
            {
                window.draw(**nodeIter);
            }
        }

        // Finally, display the rendered frame on screen
        window.display();
    }

    delete game;

    return EXIT_SUCCESS;
}