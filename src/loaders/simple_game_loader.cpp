#include "simple_game_loader.h"
#include "simple_game_loader_p.h"
#include "../gamedata/game.h"
#include "../gamedata/node.h"
#include "../gamedata/edge.h"
#include "../graphics/node_sprite.h"
#include "../graphics/edge_sprite.h"
#include <vector>
#include <fstream>
#include <sstream>

namespace JCT_SFML
{
	namespace Loaders
	{
		SimpleGameLoader::SimpleGameLoader(const std::string &filename)
		{
			d = new SimpleGameLoaderPrivate();
			d->filename = filename;
			d->game = NULL;
		}

		SimpleGameLoader::~SimpleGameLoader()
		{
			delete d;
		}

		Gamedata::Game *SimpleGameLoader::game()
		{
			if(d->game == NULL)
			{
				loadGame();
			}

			return d->game;
		}

		std::vector<Graphics::NodeSprite*> SimpleGameLoader::nodeSprites()
		{
			if(d->game == NULL)
			{
				loadGame();
			}

			return d->nodeSprites;
		}

		std::vector<Graphics::EdgeSprite*> SimpleGameLoader::edgeSprites()
		{
			if(d->game == NULL)
			{
				loadGame();
			}

			return d->edgeSprites;
		}

		void SimpleGameLoader::loadGame()
		{
			d->game = new Gamedata::Game();

			std::ifstream filestream(d->filename, std::ifstream::in);

			std::vector<Gamedata::Node*> nodes;
		    std::vector<Gamedata::Edge*> edges;

		    std::string line;

			// Load nodes
			{
				getline(filestream, line);
				std::stringstream linestream(line);
				unsigned int nodeCount;
				linestream >> nodeCount;

				for(unsigned int nodeId = 0; nodeId < nodeCount; nodeId++)
				{
					std::string line;
					getline(filestream, line);
					std::stringstream linestream(line);
					float x, y;
					linestream >> x >> y;

					Gamedata::Node* node = new Gamedata::Node();
	                Graphics::NodeSprite* nodeSprite = new Graphics::NodeSprite(node);
	                nodeSprite->setPosition(sf::Vector2f(x, y));
	                d->game->addNode(node);
	                nodes.push_back(node);
	                d->nodeSprites.push_back(nodeSprite);
				}
			}

	        // Load edges with Sprites
	        {
		        getline(filestream, line);
				std::stringstream linestream(line);
				unsigned int edgeCount;
				linestream >> edgeCount;

				for(unsigned int edgeId = 0; edgeId < edgeCount; edgeId++)
				{
					std::string line;
					getline(filestream, line);
					std::stringstream linestream(line);
					unsigned int to, from;
					bool visible;
					linestream >> to >> from >> visible;

					Gamedata::Node* fromNode = nodes[from];
					Gamedata::Node* toNode = nodes[to];

					Gamedata::Edge* edge = new Gamedata::Edge(fromNode, toNode);
	                fromNode->addEdge(edge);

	                if(visible)
	                {
	                	Graphics::EdgeSprite* edgeSprite = new Graphics::EdgeSprite(d->nodeSprites[from],
	                              		                                            d->nodeSprites[to]);
	                	d->edgeSprites.push_back(edgeSprite);
	                }
				}
			}
	    }
	}
}