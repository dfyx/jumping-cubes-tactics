#ifndef JCT_SFML_LOADERS_SIMPLE_GAME_LOADER_H
#define JCT_SFML_LOADERS_SIMPLE_GAME_LOADER_H

#include "game_loader.h"
#include <string>

namespace JCT_SFML
{
	namespace Loaders
	{
		class SimpleGameLoader : public GameLoader
		{
		private:
			class SimpleGameLoaderPrivate *d;

		public:
			SimpleGameLoader(const std::string &filename);
			~SimpleGameLoader();

			Gamedata::Game* game();

			std::vector<Graphics::NodeSprite*> nodeSprites();
			std::vector<Graphics::EdgeSprite*> edgeSprites();

		protected:
			void loadGame();
		};
	}
}
#endif // JCT_SFML_LOADERS_SIMPLE_GAME_LOADER_H