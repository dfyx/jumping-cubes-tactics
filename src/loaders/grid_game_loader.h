#ifndef JCT_SFML_LOADERS_GRID_GAME_LOADER_H
#define JCT_SFML_LOADERS_GRID_GAME_LOADER_H

#include "game_loader.h"

namespace JCT_SFML
{
	namespace Loaders
	{
		class GridGameLoader : public GameLoader
		{
		private:
			class GridGameLoaderPrivate *d;

		public:
			GridGameLoader(unsigned int width, unsigned int height, float distance = 70.0);
			~GridGameLoader();

			Gamedata::Game* game();

			std::vector<Graphics::NodeSprite*> nodeSprites();
			std::vector<Graphics::EdgeSprite*> edgeSprites();

		protected:
			void generateGame();
		};
	}
}
#endif // JCT_SFML_LOADERS_GRID_GAME_LOADER_H