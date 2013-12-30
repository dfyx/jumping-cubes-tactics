#include "grid_game_loader.h"
#include "grid_game_loader_p.h"
#include "../gamedata/game.h"
#include "../gamedata/node.h"
#include "../gamedata/edge.h"
#include "../graphics/node_sprite.h"
#include "../graphics/edge_sprite.h"
#include <vector>

namespace JCT_SFML
{
	namespace Loaders
	{
		GridGameLoader::GridGameLoader(unsigned int width, unsigned int height, float distance)
		{
			d = new GridGameLoaderPrivate();
			d->width = width;
			d->height = height;
			d->distance = distance;
			d->game = NULL;
		}

		GridGameLoader::~GridGameLoader()
		{
			delete d;
		}

		Gamedata::Game *GridGameLoader::game()
		{
			if(d->game == NULL)
			{
				generateGame();
			}

			return d->game;
		}

		std::vector<Graphics::NodeSprite*> GridGameLoader::nodeSprites()
		{
			if(d->game == NULL)
			{
				generateGame();
			}

			return d->nodeSprites;
		}

		std::vector<Graphics::EdgeSprite*> GridGameLoader::edgeSprites()
		{
			if(d->game == NULL)
			{
				generateGame();
			}

			return d->edgeSprites;
		}

		void GridGameLoader::generateGame()
		{
			d->game = new Gamedata::Game();

			std::vector<Gamedata::Node*> nodes;
		    std::vector<Gamedata::Edge*> edges;

			// Generate nodes
	        for(int y = 0; y < d->height; y++)
	        {
	            for(int x = 0; x < d->width; x++)
	            {
	                Gamedata::Node* node = new Gamedata::Node();
	                Graphics::NodeSprite* nodeSprite = new Graphics::NodeSprite(node);
	                nodeSprite->setPosition(sf::Vector2f((x + 1) * d->distance, (y + 1) * d->distance));
	                d->game->addNode(node);
	                nodes.push_back(node);
	                d->nodeSprites.push_back(nodeSprite);
	            }
	        }

	        // Generate edges
	        for(int y = 0; y < d->height; y++)
	        {
	            for(int x = 0; x < d->width; x++)
	            {
	                Gamedata::Node *node = nodes[y * d->width + x];
	                Graphics::NodeSprite *nodeSprite = d->nodeSprites[y * d->width + x];

	                if(x > 0)
	                {
	                    size_t index = y * d->width + x - 1;
	                    Gamedata::Edge* edge = new Gamedata::Edge(node,
	                                                              nodes[index]);
	                    Graphics::EdgeSprite* edgeSprite = new Graphics::EdgeSprite(nodeSprite,
	                                                                                d->nodeSprites[index]);

	                    node->addEdge(edge);
	                    edges.push_back(edge);
	                    d->edgeSprites.push_back(edgeSprite);
	                }

	                if(y > 0)
	                {
	                    size_t index = (y - 1) * d->width + x;
	                    Gamedata::Edge* edge = new Gamedata::Edge(node,
	                                                              nodes[index]);
	                    Graphics::EdgeSprite* edgeSprite = new Graphics::EdgeSprite(nodeSprite,
	                                                                                d->nodeSprites[index]);

	                    node->addEdge(edge);
	                    edges.push_back(edge);
	                    d->edgeSprites.push_back(edgeSprite);
	                }

	                if(x < d->width - 1)
	                {
	                    size_t index = y * d->width + x + 1;
	                    Gamedata::Edge* edge = new Gamedata::Edge(node,
	                                                              nodes[index]);

	                    node->addEdge(edge);
	                }

	                if(y < d->height - 1)
	                {
	                    size_t index = (y + 1) * d->width + x;
	                    Gamedata::Edge* edge = new Gamedata::Edge(node,
	                                                              nodes[index]);

	                    node->addEdge(edge);
	                }
	            }
	        }
	    }
	}
}