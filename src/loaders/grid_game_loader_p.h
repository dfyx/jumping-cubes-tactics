#ifndef JCT_SFML_LOADERS_GRID_GAME_LOADER_P_H
#define JCT_SFML_LOADERS_GRID_GAME_LOADER_P_H

#include "game_loader.h"

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
		class GridGameLoaderPrivate
		{
		public:
			unsigned int width, height;
			float distance;
			Gamedata::Game *game;
			std::vector<Graphics::NodeSprite*> nodeSprites;
			std::vector<Graphics::EdgeSprite*> edgeSprites;
		};
	}
}
#endif // JCT_SFML_LOADERS_GRID_GAME_LOADER_P_H