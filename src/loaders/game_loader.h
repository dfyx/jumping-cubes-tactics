#ifndef JCT_SFML_LOADERS_GAMELOADER_H
#define JCT_SFML_LOADERS_GAMELOADER_H

#include <vector>

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
		class GameLoader
		{
		public:
			virtual Gamedata::Game* game() = 0;

			virtual std::vector<Graphics::NodeSprite*> nodeSprites() = 0;
			virtual std::vector<Graphics::EdgeSprite*> edgeSprites() = 0;
		};
	}
}
#endif // JCT_SFML_LOADERS_GAMELOADER_H