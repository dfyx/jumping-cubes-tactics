#include "json_game_loader.h"
#include "json_game_loader_p.h"
#include "../gamedata/game.h"
#include "../gamedata/node.h"
#include "../gamedata/edge.h"
#include "../graphics/node_sprite.h"
#include "../graphics/edge_sprite.h"
#include <vector>
#include <json/json.h>
#include <iostream>
#include <fstream>

namespace JCT_SFML
{
	namespace Loaders
	{
		JsonGameLoader::JsonGameLoader(const std::string &filename)
		{
			d = new JsonGameLoaderPrivate();
			d->filename = filename;
			d->game = NULL;
		}

		JsonGameLoader::~JsonGameLoader()
		{
			delete d;
		}

		Gamedata::Game *JsonGameLoader::game()
		{
			if(d->game == NULL)
			{
				loadGame();
			}

			return d->game;
		}

		std::vector<Graphics::NodeSprite*> JsonGameLoader::nodeSprites()
		{
			if(d->game == NULL)
			{
				loadGame();
			}

			return d->nodeSprites;
		}

		std::vector<Graphics::EdgeSprite*> JsonGameLoader::edgeSprites()
		{
			if(d->game == NULL)
			{
				loadGame();
			}

			return d->edgeSprites;
		}

		void JsonGameLoader::loadGame()
		{
			d->game = new Gamedata::Game();

			std::ifstream filestream(d->filename, std::ifstream::in);

			Json::Value root;
			Json::Reader reader;
			if(!reader.parse(filestream, root)) {
				std::cout << reader.getFormattedErrorMessages();
				return;
			}

			std::vector<Gamedata::Node*> nodes;
		    std::vector<Gamedata::Edge*> edges;

		    const Json::Value jsonNodes = root["nodes"];
		    for(int index = 0; index < jsonNodes.size(); index++)
		    {
		    	const Json::Value jsonNode = jsonNodes[index];
		    	float x = jsonNode["x"].asFloat();
		    	float y = jsonNode["y"].asFloat();

		    	Gamedata::Node* node = new Gamedata::Node();
                Graphics::NodeSprite* nodeSprite = new Graphics::NodeSprite(node);
                nodeSprite->setPosition(sf::Vector2f(x, y));
                d->game->addNode(node);
                nodes.push_back(node);
                d->nodeSprites.push_back(nodeSprite);
		    }

		    const Json::Value jsonEdges = root["edges"];
		    for(int index = 0; index < jsonEdges.size(); index++) {
		    	const Json::Value jsonEdge = jsonEdges[index];
		    	unsigned int to = jsonEdge["to"].asInt();
		    	unsigned int from = jsonEdge["from"].asInt();
				bool invisible = jsonEdge["invisible"].asBool();
				bool bidirectional = jsonEdge["bidirectional"].asBool();

		    	Gamedata::Node* fromNode = nodes[from];
				Gamedata::Node* toNode = nodes[to];

				Gamedata::Edge* edge = new Gamedata::Edge(fromNode, toNode);
                fromNode->addEdge(edge);

                if(bidirectional)
				{
					edge = new Gamedata::Edge(toNode, fromNode);
                	toNode->addEdge(edge);
				}

                if(!invisible)
                {
                	Graphics::EdgeSprite* edgeSprite = new Graphics::EdgeSprite(d->nodeSprites[from],
                              		                                            d->nodeSprites[to]);
                	d->edgeSprites.push_back(edgeSprite);
                }
		    }
	    }
	}
}