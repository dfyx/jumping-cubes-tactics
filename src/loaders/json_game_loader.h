#ifndef JCT_SFML_LOADERS_JSON_GAME_LOADER_H
#define JCT_SFML_LOADERS_JSON_GAME_LOADER_H

#include "game_loader.h"
#include <string>

namespace JCT_SFML
{
	namespace Loaders
	{
		class JsonGameLoader : public GameLoader
		{
		private:
			class JsonGameLoaderPrivate *d;

		public:
			JsonGameLoader(const std::string &filename);
			~JsonGameLoader();

			Gamedata::Game* game();

			std::vector<Graphics::NodeSprite*> nodeSprites();
			std::vector<Graphics::EdgeSprite*> edgeSprites();

		protected:
			void loadGame();
		};
	}
}
#endif // JCT_SFML_LOADERS_JSON_GAME_LOADER_H