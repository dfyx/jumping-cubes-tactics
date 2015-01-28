#ifndef JCT_SFML_LOADERS_JSON_GAME_LOADER_P_H
#define JCT_SFML_LOADERS_JSON_GAME_LOADER_P_H

#include "game_loader.h"
#include <string>

namespace JCT_SFML
{
	namespace Gamedata
	{
		class Game;
	}

	namespace Graphics
	{
		class NodeSprite;
		class EdgeSprite;
	}

	namespace Loaders
	{
		class JsonGameLoaderPrivate
		{
		public:
			std::string filename;
			Gamedata::Game *game;
			std::vector<Graphics::NodeSprite*> nodeSprites;
			std::vector<Graphics::EdgeSprite*> edgeSprites;
		};
	}
}
#endif // JCT_SFML_LOADERS_JSON_GAME_LOADER_P_H